#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->pushButton->setStatusTip("blabla...");

    ui->pushButton->setIcon(QIcon(":/image/add.png"));


}

MainWindow::~MainWindow()
{
    delete ui;
}
