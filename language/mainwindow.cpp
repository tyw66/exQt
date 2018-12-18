#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
#ifdef TEST_MODE
    QMessageBox::information(this,tr("HINT."),tr("this is some test words."));
#endif

    if(isTranslate){
        translator.load("./test_zh.qm");
        qApp->installTranslator(&translator);
    }
    else{
        bool flag = qApp->removeTranslator(&translator);
        qDebug()<<flag;
    }
    isTranslate=!isTranslate;
}


