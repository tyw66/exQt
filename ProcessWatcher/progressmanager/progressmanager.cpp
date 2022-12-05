/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company.  For licensing terms and
** conditions see http://www.qt.io/terms-conditions.  For further information
** use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file.  Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, The Qt Company gives you certain additional
** rights.  These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#include "futureprogress.h"
#include "progressmanager_p.h"
#include "progressbar.h"
#include "progressview.h"
//#include "../actionmanager/actionmanager.h"
//#include "../actionmanager/command.h"
//#include "../icontext.h"
//#include "../coreconstants.h"
//#include "../icore.h"
//#include "../statusbarwidget.h"


//#include <extensionsystem/pluginmanager.h>
//#include <utils/hostosinfo.h>
//#include <utils/qtcassert.h>
//#include <utils/stylehelper.h>
//#include <utils/theme/theme.h>

#include <QAction>
#include <QEvent>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainter>
#include <QPropertyAnimation>
#include <QStyle>
#include <QStyleOption>
#include <QTimer>
#include <QVariant>

#include <math.h>

static const char kSettingsGroup[] = "Progress";
static const char kDetailsPinned[] = "DetailsPinned";

using namespace Core;
using namespace Core::Internal;
//using namespace Utils;

static ProgressManagerPrivate *m_instance = 0;

ProgressManagerPrivate::ProgressManagerPrivate()
  : m_applicationTask(0),
    m_currentStatusDetailsWidget(0),
    m_opacityEffect(new QGraphicsOpacityEffect(this)),
    m_progressViewPinned(false),
    m_hovered(false)
{
    m_instance = this;
    m_progressView = new ProgressView;
    // withDelay, so the statusBarWidget has the chance to get the enter event
    connect(m_progressView, SIGNAL(hoveredChanged(bool)), this, SLOT(updateVisibilityWithDelay()));
//    connect(ICore::instance(), SIGNAL(coreAboutToClose()), this, SLOT(cancelAllRunningTasks()));
}

ProgressManagerPrivate::~ProgressManagerPrivate()
{
    stopFadeOfSummaryProgress();
    qDeleteAll(m_taskList);
    m_taskList.clear();
//    ExtensionSystem::PluginManager::removeObject(m_statusBarWidgetContainer);
    delete m_statusBarWidgetContainer;
    cleanup();
    m_instance = 0;
}

void ProgressManagerPrivate::readSettings()
{
//    QSettings *settings = ICore::settings();
//    settings->beginGroup(QLatin1String(kSettingsGroup));
//    m_progressViewPinned = settings->value(QLatin1String(kDetailsPinned), false).toBool();
//    settings->endGroup();
}

void ProgressManagerPrivate::init()
{
    readSettings();

    m_statusBarWidgetContainer = new StatusBarWidget;
    m_statusBarWidget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout(m_statusBarWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    m_statusBarWidget->setLayout(layout);
    m_summaryProgressWidget = new QWidget(m_statusBarWidget);
    m_summaryProgressWidget->setVisible(!m_progressViewPinned);
    m_summaryProgressWidget->setGraphicsEffect(m_opacityEffect);
    m_summaryProgressLayout = new QHBoxLayout(m_summaryProgressWidget);
    m_summaryProgressLayout->setContentsMargins(0, 0, 0, 0);
    m_summaryProgressLayout->setSpacing(0);
    m_summaryProgressWidget->setLayout(m_summaryProgressLayout);
    m_summaryProgressBar = new ProgressBar(m_summaryProgressWidget);
    m_summaryProgressBar->setMinimumWidth(70);
    m_summaryProgressBar->setTitleVisible(false);
    m_summaryProgressBar->setSeparatorVisible(false);
    m_summaryProgressBar->setCancelEnabled(false);
    m_summaryProgressLayout->addWidget(m_summaryProgressBar);
    layout->addWidget(m_summaryProgressWidget);
    ToggleButton *toggleButton = new ToggleButton(m_statusBarWidget);
    layout->addWidget(toggleButton);
    m_statusBarWidgetContainer->setWidget(m_statusBarWidget);
    m_statusBarWidgetContainer->setPosition(StatusBarWidget::RightCorner);
    ExtensionSystem::PluginManager::addObject(m_statusBarWidgetContainer);
    m_statusBarWidget->installEventFilter(this);

    QAction *toggleProgressView = new QAction(tr("Toggle Progress Details"), this);
    toggleProgressView->setCheckable(true);
    toggleProgressView->setChecked(m_progressViewPinned);
    // we have to set an transparent icon to prevent the tool button to show text
    QPixmap p(1, 1);
    p.fill(Qt::transparent);
    toggleProgressView->setIcon(QIcon(p));
    Command *cmd = ActionManager::registerAction(toggleProgressView,
                                                 "QtCreator.ToggleProgressDetails");
    cmd->setDefaultKeySequence(QKeySequence(HostOsInfo::isMacHost()
                                               ? tr("Ctrl+Shift+0")
                                               : tr("Alt+Shift+0")));
    connect(toggleProgressView, SIGNAL(toggled(bool)), this, SLOT(progressDetailsToggled(bool)));
    toggleButton->setDefaultAction(cmd->action());

    m_progressView->setVisible(m_progressViewPinned);

    initInternal();
}

void ProgressManagerPrivate::doCancelTasks(Id type)
{
    bool found = false;
    QMap<QFutureWatcher<void> *, Id>::iterator task = m_runningTasks.begin();
    while (task != m_runningTasks.end()) {
        if (task.value() != type) {
            ++task;
            continue;
        }
        found = true;
        disconnect(task.key(), SIGNAL(finished()), this, SLOT(taskFinished()));
        if (m_applicationTask == task.key())
            disconnectApplicationTask();
        task.key()->cancel();
        delete task.key();
        task = m_runningTasks.erase(task);
    }
    if (found) {
        updateSummaryProgressBar();
        emit allTasksFinished(type);
    }
}

bool ProgressManagerPrivate::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == m_statusBarWidget && event->type() == QEvent::Enter) {
        m_hovered = true;
        updateVisibility();
    } else if (obj == m_statusBarWidget && event->type() == QEvent::Leave) {
        m_hovered = false;
        // give the progress view the chance to get the mouse enter event
        updateVisibilityWithDelay();
    } else if (obj == m_statusBarWidget && event->type() == QEvent::MouseButtonPress
               && !m_taskList.isEmpty()) {
        QMouseEvent *me = static_cast<QMouseEvent *>(event);
        if (me->button() == Qt::LeftButton && !me->modifiers()) {
            FutureProgress *progress = m_currentStatusDetailsProgress;
            if (!progress)
                progress = m_taskList.last();
            // don't send signal directly from an event filter, event filters should
            // do as little a possible
            QTimer::singleShot(0, progress, SIGNAL(clicked()));
            event->accept();
            return true;
        }
    }
    return false;
}

void ProgressManagerPrivate::cancelAllRunningTasks()
{
    QMap<QFutureWatcher<void> *, Id>::const_iterator task = m_runningTasks.constBegin();
    while (task != m_runningTasks.constEnd()) {
        disconnect(task.key(), SIGNAL(finished()), this, SLOT(taskFinished()));
        if (m_applicationTask == task.key())
            disconnectApplicationTask();
        task.key()->cancel();
        delete task.key();
        ++task;
    }
    m_runningTasks.clear();
    updateSummaryProgressBar();
}

FutureProgress *ProgressManagerPrivate::doAddTask(const QFuture<void> &future, const QString &title,
                                                int type, ProgressFlags flags)
{
    // watch
    QFutureWatcher<void> *watcher = new QFutureWatcher<void>();
    m_runningTasks.insert(watcher, type);
    connect(watcher, SIGNAL(progressRangeChanged(int,int)), this, SLOT(updateSummaryProgressBar()));
    connect(watcher, SIGNAL(progressValueChanged(int)), this, SLOT(updateSummaryProgressBar()));
    connect(watcher, SIGNAL(finished()), this, SLOT(taskFinished()));
    watcher->setFuture(future);

    // handle application task
    if (flags & ShowInApplicationIcon) {
        if (m_applicationTask)
            disconnectApplicationTask();
        m_applicationTask = watcher;
        setApplicationProgressRange(future.progressMinimum(), future.progressMaximum());
        setApplicationProgressValue(future.progressValue());
        connect(m_applicationTask, SIGNAL(progressRangeChanged(int,int)),
                this, SLOT(setApplicationProgressRange(int,int)));
        connect(m_applicationTask, SIGNAL(progressValueChanged(int)),
                this, SLOT(setApplicationProgressValue(int)));
        setApplicationProgressVisible(true);
    }

    // create FutureProgress and manage task list
    removeOldTasks(type);
    if (m_taskList.size() == 10)
        removeOneOldTask();
    FutureProgress *progress = new FutureProgress;
    progress->setTitle(title);
    progress->setFuture(future);

    m_progressView->addProgressWidget(progress);
    m_taskList.append(progress);
    progress->setType(type);
    if (flags.testFlag(ProgressManager::KeepOnFinish))
        progress->setKeepOnFinish(FutureProgress::KeepOnFinishTillUserInteraction);
    else
        progress->setKeepOnFinish(FutureProgress::HideOnFinish);
    connect(progress, SIGNAL(hasErrorChanged()), this, SLOT(updateSummaryProgressBar()));
    connect(progress, SIGNAL(removeMe()), this, SLOT(slotRemoveTask()));
    connect(progress, SIGNAL(fadeStarted()), this, SLOT(updateSummaryProgressBar()));
    connect(progress, SIGNAL(statusBarWidgetChanged()), this, SLOT(updateStatusDetailsWidget()));
    updateStatusDetailsWidget();

    emit taskStarted(type);
    return progress;
}

ProgressView *ProgressManagerPrivate::progressView()
{
    return m_progressView;
}

void ProgressManagerPrivate::taskFinished()
{
    QObject *taskObject = sender();
//    QTC_ASSERT(taskObject, return);
    QFutureWatcher<void> *task = static_cast<QFutureWatcher<void> *>(taskObject);
    if (m_applicationTask == task)
        disconnectApplicationTask();
    Id type = m_runningTasks.value(task);
    m_runningTasks.remove(task);
    delete task;
    updateSummaryProgressBar();

    if (!m_runningTasks.key(type, 0))
        emit allTasksFinished(type);
}

void ProgressManagerPrivate::disconnectApplicationTask()
{
    disconnect(m_applicationTask, SIGNAL(progressRangeChanged(int,int)),
            this, SLOT(setApplicationProgressRange(int,int)));
    disconnect(m_applicationTask, SIGNAL(progressValueChanged(int)),
            this, SLOT(setApplicationProgressValue(int)));
    setApplicationProgressVisible(false);
    m_applicationTask = 0;
}

void ProgressManagerPrivate::updateSummaryProgressBar()
{
    m_summaryProgressBar->setError(hasError());
    updateVisibility();
    if (m_runningTasks.isEmpty()) {
        m_summaryProgressBar->setFinished(true);
        if (m_taskList.isEmpty() || isLastFading())
            fadeAwaySummaryProgress();
        return;
    }

    stopFadeOfSummaryProgress();

    m_summaryProgressBar->setFinished(false);
    QMapIterator<QFutureWatcher<void> *, Id> it(m_runningTasks);
    static const int TASK_RANGE = 100;
    int value = 0;
    while (it.hasNext()) {
        it.next();
        QFutureWatcher<void> *watcher = it.key();
        int min = watcher->progressMinimum();
        int range = watcher->progressMaximum() - min;
        if (range > 0)
            value += TASK_RANGE * (watcher->progressValue() - min) / range;
    }
    m_summaryProgressBar->setRange(0, TASK_RANGE * m_runningTasks.size());
    m_summaryProgressBar->setValue(value);
}

void ProgressManagerPrivate::fadeAwaySummaryProgress()
{
    stopFadeOfSummaryProgress();
    m_opacityAnimation = new QPropertyAnimation(m_opacityEffect, "opacity");
    m_opacityAnimation->setDuration(StyleHelper::progressFadeAnimationDuration);
    m_opacityAnimation->setEndValue(0.);
    connect(m_opacityAnimation, SIGNAL(finished()), this, SLOT(summaryProgressFinishedFading()));
    m_opacityAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void ProgressManagerPrivate::stopFadeOfSummaryProgress()
{
    if (m_opacityAnimation) {
        m_opacityAnimation->stop();
        m_opacityEffect->setOpacity(1.);
        delete m_opacityAnimation;
    }
}

bool ProgressManagerPrivate::hasError() const
{
    foreach (FutureProgress *progress, m_taskList)
        if (progress->hasError())
            return true;
    return false;
}

bool ProgressManagerPrivate::isLastFading() const
{
    if (m_taskList.isEmpty())
        return false;
    foreach (FutureProgress *progress, m_taskList) {
        if (!progress->isFading()) // we still have progress bars that are not fading
            return false;
    }
    return true;
}

void ProgressManagerPrivate::slotRemoveTask()
{
    FutureProgress *progress = qobject_cast<FutureProgress *>(sender());
    QTC_ASSERT(progress, return);
    Id type = progress->type();
    removeTask(progress);
    removeOldTasks(type, true);
}

void ProgressManagerPrivate::removeOldTasks(const Id type, bool keepOne)
{
    bool firstFound = !keepOne; // start with false if we want to keep one
    QList<FutureProgress *>::iterator i = m_taskList.end();
    while (i != m_taskList.begin()) {
        --i;
        if ((*i)->type() == type) {
            if (firstFound && ((*i)->future().isFinished() || (*i)->future().isCanceled())) {
                deleteTask(*i);
                i = m_taskList.erase(i);
            }
            firstFound = true;
        }
    }
    updateSummaryProgressBar();
    updateStatusDetailsWidget();
}

void ProgressManagerPrivate::removeOneOldTask()
{
    if (m_taskList.isEmpty())
        return;
    // look for oldest ended process
    for (QList<FutureProgress *>::iterator i = m_taskList.begin(); i != m_taskList.end(); ++i) {
        if ((*i)->future().isFinished()) {
            deleteTask(*i);
            i = m_taskList.erase(i);
            return;
        }
    }
    // no ended process, look for a task type with multiple running tasks and remove the oldest one
    for (QList<FutureProgress *>::iterator i = m_taskList.begin(); i != m_taskList.end(); ++i) {
        Id type = (*i)->type();

        int taskCount = 0;
        foreach (FutureProgress *p, m_taskList)
            if (p->type() == type)
                ++taskCount;

        if (taskCount > 1) { // don't care for optimizations it's only a handful of entries
            deleteTask(*i);
            i = m_taskList.erase(i);
            return;
        }
    }

    // no ended process, no type with multiple processes, just remove the oldest task
    FutureProgress *task = m_taskList.takeFirst();
    deleteTask(task);
    updateSummaryProgressBar();
    updateStatusDetailsWidget();
}

void ProgressManagerPrivate::removeTask(FutureProgress *task)
{
    m_taskList.removeAll(task);
    deleteTask(task);
    updateSummaryProgressBar();
    updateStatusDetailsWidget();
}

void ProgressManagerPrivate::deleteTask(FutureProgress *progress)
{
    m_progressView->removeProgressWidget(progress);
    progress->hide();
    progress->deleteLater();
}

void ProgressManagerPrivate::updateVisibility()
{
    m_progressView->setVisible(m_progressViewPinned || m_hovered || m_progressView->isHovered());
    m_summaryProgressWidget->setVisible((!m_runningTasks.isEmpty() || !m_taskList.isEmpty())
                                     && !m_progressViewPinned);
}

void ProgressManagerPrivate::updateVisibilityWithDelay()
{
    QTimer::singleShot(150, this, SLOT(updateVisibility()));
}

void ProgressManagerPrivate::updateStatusDetailsWidget()
{
    QWidget *candidateWidget = 0;
    // get newest progress with a status bar widget
    QList<FutureProgress *>::iterator i = m_taskList.end();
    while (i != m_taskList.begin()) {
        --i;
        candidateWidget = (*i)->statusBarWidget();
        if (candidateWidget) {
            m_currentStatusDetailsProgress = *i;
            break;
        }
    }

    if (candidateWidget == m_currentStatusDetailsWidget)
        return;

    if (m_currentStatusDetailsWidget) {
        m_currentStatusDetailsWidget->hide();
        m_summaryProgressLayout->removeWidget(m_currentStatusDetailsWidget);
    }

    if (candidateWidget) {
        m_summaryProgressLayout->insertWidget(0, candidateWidget);
        candidateWidget->show();
    }

    m_currentStatusDetailsWidget = candidateWidget;
}

void ProgressManagerPrivate::summaryProgressFinishedFading()
{
    m_summaryProgressWidget->setVisible(false);
    m_opacityEffect->setOpacity(1.);
}

void ProgressManagerPrivate::progressDetailsToggled(bool checked)
{
    m_progressViewPinned = checked;
    updateVisibility();

    QSettings *settings = ICore::settings();
    settings->beginGroup(QLatin1String(kSettingsGroup));
    settings->setValue(QLatin1String(kDetailsPinned), m_progressViewPinned);
    settings->endGroup();
}

ToggleButton::ToggleButton(QWidget *parent)
    : QToolButton(parent)
{
    setToolButtonStyle(Qt::ToolButtonIconOnly);
    if (creatorTheme()->widgetStyle() == Theme::StyleFlat) {
        QPalette p = palette();
        p.setBrush(QPalette::Base, creatorTheme()->color(Theme::ToggleButtonBackgroundColor));
        setPalette(p);
    }
}

QSize ToggleButton::sizeHint() const
{
    return QSize(13, 12); // Uneven width, because the arrow's width is also uneven.
}

void ToggleButton::paintEvent(QPaintEvent *event)
{
    QToolButton::paintEvent(event);
    QPainter p(this);
    QStyleOption arrowOpt;
    arrowOpt.initFrom(this);
    arrowOpt.rect.adjust(2, 0, -1, -2);
    StyleHelper::drawArrow(QStyle::PE_IndicatorArrowUp, &p, &arrowOpt);
}


ProgressManager::ProgressManager()
{
}

ProgressManager::~ProgressManager()
{
}

ProgressManager *ProgressManager::instance()
{
    return m_instance;
}

FutureProgress *ProgressManager::addTask(const QFuture<void> &future, const QString &title, int type, ProgressFlags flags)
{
    return m_instance->doAddTask(future, title, type, flags);
}

/*!
    Shows a progress indicator for task given by the QFuture given by
    the QFutureInterface \a futureInterface.
    The progress indicator shows the specified \a title along with the progress bar.
    The progress indicator will increase monotonically with time, at \a expectedSeconds
    it will reach about 80%, and continue to increase with a decreasingly slower rate.

    \sa addTask
*/

FutureProgress *ProgressManager::addTimedTask(const QFutureInterface<void> &futureInterface, const QString &title,
                                              int type, int expectedSeconds, ProgressFlags flags)
{
    QFutureInterface<void> dummy(futureInterface); // Need mutable to access .future()
    FutureProgress *fp = m_instance->doAddTask(dummy.future(), title, type, flags);
    (void) new ProgressTimer(fp, futureInterface, expectedSeconds);
    return fp;
}

void ProgressManager::setApplicationLabel(const QString &text)
{
    m_instance->doSetApplicationLabel(text);
}

void ProgressManager::cancelTasks(Id type)
{
    if (m_instance)
        m_instance->doCancelTasks(type);
}


ProgressTimer::ProgressTimer(QObject *parent,
                             const QFutureInterface<void> &futureInterface,
                             int expectedSeconds)
    : QTimer(parent),
      m_futureInterface(futureInterface),
      m_expectedTime(expectedSeconds),
      m_currentTime(0)
{
    m_futureWatcher.setFuture(m_futureInterface.future());

    m_futureInterface.setProgressRange(0, 100);
    m_futureInterface.setProgressValue(0);

    setInterval(1000); // 1 second
    connect(this, SIGNAL(timeout()), this, SLOT(handleTimeout()));
    connect(&m_futureWatcher, SIGNAL(started()), this, SLOT(start()));
}

void ProgressTimer::handleTimeout()
{
    ++m_currentTime;

    // This maps expectation to atan(1) to Pi/4 ~= 0.78, i.e. snaps
    // from 78% to 100% when expectations are met at the time the
    // future finishes. That's not bad for a random choice.
    const double mapped = atan2(double(m_currentTime), double(m_expectedTime));
    const double progress = 100 * 2 * mapped / 3.14;
    m_futureInterface.setProgressValue(int(progress));
}

