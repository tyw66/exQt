#include "mainwindow.h"
#include "ui_mainwindow.h"
bool MainWindow::flag = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1000,1000);




}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    flag = !flag;
    if(flag){
        maskMe();
    }
    else{
        clearMask();
    }
    show();
}

void MainWindow::maskMe()
{
    QPolygon region;
    region.setPoints(3,20,200,220,0,420,200);
    setMask(region);
}
