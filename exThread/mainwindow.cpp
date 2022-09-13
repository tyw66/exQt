#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThread>
#include <QObject>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    m_stopWatch = new QThread(this);
    //    connect(m_stopWatch, &WorkerThread::resultReady, this, &MainWindow::onShowResult);
    //    connect(m_stopWatch, &WorkerThread::finished, workerThread, &QObject::deleteLater);
    //    workerThread->start();

    m_stopWatch = new WorkerThread(this);
    connect(m_stopWatch, &WorkerThread::resultReady, this, &MainWindow::onShowResult);
    m_stopWatch->start();

    m_thread = new QThread();
    qDebug() << "HAHAH" <<  (m_thread->thread() == this->thread());
}

MainWindow::~MainWindow()
{
    m_stopWatch->quit();
    m_thread->quit();
    delete ui;
}

void MainWindow::onShowResult(QString res)
{
    //    ui->textEdit->append(res);
    //    ui->progressBar->setValue(res.toInt());
    ui->label_stopwatch->setText(res);
}


void MainWindow::on_pushButton_1_clicked()
{
    //    connect(m_stopWatch, &WorkerThread::finished, m_stopWatch, &QObject::deleteLater);
    m_stopWatch->flag = true;
    m_stopWatch->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    m_stopWatch->flag = false;
}


void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << foo.parent();
    foo.moveToThread(m_thread);
    qDebug() << connect(&foo, &Foo2::resultReady,this,&MainWindow::onShowResult);
    qDebug() << connect(this,&MainWindow::startIt,&foo,&Foo2::onClock);
    m_thread->start();


}

void MainWindow::on_pushButton_4_clicked()
{
    emit startIt();
}
