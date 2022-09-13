#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int i=0;
    while(true){
        //        QThread::msleep(1000);
        ui->progressBar->setValue(i*10);
        i++;
        qApp->processEvents(QEventLoop::ExcludeUserInputEvents);

        if(i>100){
            i=1;
        }
    }
}
