#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

#include<QDebug>

#include "./langwidget.h"


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

void MainWindow::on_actionLanguge_triggered()
{
    LangDialog langDialog;
    langDialog.exec();
}
