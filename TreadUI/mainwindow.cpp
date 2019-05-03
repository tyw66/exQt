#include "mainwindow.h"
#include "ui_mainwindow.h"

#include"mythread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(test()));

    connect(ui->pushButton_2,SIGNAL(clicked),this,SLOT(test_process()));

    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(test()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test()
{
    ui->listWidget->clear();
    for(int i=0;i<100000;i++){
        QListWidgetItem* item=new QListWidgetItem(ui->listWidget);
        item->setText(QString::number(i));
        ui->listWidget->addItem(item);
    }
}

//第一个分级，当一个事件处理程序知道自己将执行耗时很长的操作时，可以调用QCoreApplication::processEvents() 方法
//等待消息队列中的方法都执行完再执行。
//当然这是一个最基本的方法，只适用与简单的情况，如果事件队列中的另一程序也调用了该方法则会出现死锁。
void MainWindow::test_process()
{

}

void MainWindow::test_thread()
{
    MyThread mthread;
    mthread.run();
}

