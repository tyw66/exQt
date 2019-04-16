#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isTranslate = true;
    translator.load("./test_zh.qm");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(!isTranslate){
        qApp->installTranslator(&translator);
    }
    else{
        qApp->removeTranslator(&translator);
    }
    isTranslate=!isTranslate;
}


