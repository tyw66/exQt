#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include <QFutureWatcher>
#include <QtConcurrent/QtConcurrentRun>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_progressView = new ProgressView();
    ui->processbarLayout->addWidget(m_progressView);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_a_clicked()
{
    QFutureWatcher<void> *watcher = new QFutureWatcher<void>();
    connect(watcher,SIGNAL(finished()),this,SLOT(postWorkA()));
    watcher->setFuture(QtConcurrent::run(this,&MainWindow::workA));

    m_progressView->addTask(watcher->future(),tr("Doing Work A..."));

}

void MainWindow::workA()
{
    int i = 0;
    while(i < 100000){
        qDebug() << i++;
    }
}
void MainWindow::postWorkA()
{
    //长耗时后继续做的事情
    ui->textEdit->append("work A ok! \n");

    //删除这个watcher
    QFutureWatcher<void>*watcher = static_cast<QFutureWatcher<void>* >(sender());
    if(watcher){
        watcher->deleteLater();
        qDebug() << "delete watcher A";
    }
}



void MainWindow::on_pushButton_b_clicked()
{
    workB();
    postWorkB();
}


#include <QThread>
void MainWindow::workB()
{
    qDebug() << "start work B";
    QThread::sleep(ui->spinBox->value());
    qDebug() << "finish work B";
}



void MainWindow::postWorkB()
{
    ui->textEdit->append("work B ok! \n");
}
