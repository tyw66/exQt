#include "progressview.h"
#include <QProgressBar>
#include <QFutureWatcher>
#include <QLabel>

ProgressView::ProgressView(QWidget *parent) : QWidget(parent)
{
    m_layout = new QVBoxLayout();
    setLayout(m_layout);
}

void ProgressView::addTask(const QFuture<void> &future, const QString &title)
{
    QFutureWatcher<void> *watcher = new QFutureWatcher<void>();
    watcher->setFuture(future);

    QWidget* container = new QWidget();
    m_layout->addWidget(container);
    QLabel *titleLab = new QLabel(title,this);
    QProgressBar* bar = new QProgressBar(this);
    QVBoxLayout* layoutContainer = new QVBoxLayout();
    container->setLayout(layoutContainer);
    layoutContainer->addWidget(titleLab);
    layoutContainer->addWidget(bar);

    connect(watcher,SIGNAL(progressRangeChanged(int,int)),bar,SLOT(setRange(int,int)));
    connect(watcher,SIGNAL(progressValueChanged(int)),bar,SLOT(setValue(int)));
    connect(watcher,SIGNAL(finished()),container,SLOT(deleteLater()));
    connect(watcher,SIGNAL(finished()),watcher,SLOT(deleteLater()));
}
