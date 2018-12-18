#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    label = new EventLabel();
    label->setText("123");
    ui->layout->addWidget(label);

}

MainWindow::~MainWindow()
{
    delete ui;
}
