#include "progressbar.h"
#include <QProgressBar>
#include <QFutureWatcher>
#include <QLabel>


ProgressBar::ProgressBar(QWidget *parent) : QWidget(parent)
  ,m_opacityEffect(NULL)
{
    setMaximumSize(QSize(250,100));
    setMinimumSize(QSize(250,100));

    QLabel *titleLab = new QLabel(title,this);
    QProgressBar* bar = new QProgressBar(this);
    m_layout = new QVBoxLayout();
    m_layout->setMargin(0);
    m_layout->addWidget(titleLab);
    m_layout->addWidget(bar);

    setLayout(m_layout);
}

void ProgressBar::addTask(const QFuture<void> &future, const QString &title)
{

    m_opacityEffect = new QGraphicsOpacityEffect(this);
    container->setGraphicsEffect(m_opacityEffect);
    m_opacityAnimation = new QPropertyAnimation(m_opacityEffect, "opacity");
    m_opacityAnimation->setDuration(2000);
    m_opacityAnimation->setEndValue(0.);
    m_opacityAnimation->start(QAbstractAnimation::DeleteWhenStopped);

}



void ProgressMananger::addTask(const QFuture<void> &future, const QString &title)
{
    QFutureWatcher<void> *watcher = new QFutureWatcher<void>();
    watcher->setFuture(future);
    connect(watcher,SIGNAL(progressRangeChanged(int,int)),bar,SLOT(setRange(int,int)));
    connect(watcher,SIGNAL(progressValueChanged(int)),bar,SLOT(setValue(int)));
    connect(watcher,SIGNAL(finished()),container,SLOT(deleteLater()));
    connect(watcher,SIGNAL(finished()),watcher,SLOT(deleteLater()));

    ProgressBar bar;



}
