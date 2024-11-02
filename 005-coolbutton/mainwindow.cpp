#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initQss();

    connect(ui->pushButton,SIGNAL(clicked(bool)),ui->label,SLOT(clear()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_7,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_8,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_9,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_10,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_11,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_12,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_13,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_15,SIGNAL(clicked(bool)),this,SLOT(onClick()));
    connect(ui->pushButton_16,SIGNAL(clicked(bool)),this,SLOT(onClick()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initQss()
{
    QString qss = "QPushButton{font-family:等线;"
                  "             font-size:20px;"
                  "             padding-top:-6px;"
                  "             background-image:url(:/img/p.png);"
                  "             min-height:40px;"
                  "             border-image:url(:/img/normal.png) 22 20 40 20;"
                  "             border-top: 22px transparent;"
                  "             border-bottom: 40px transparent;"
                  "             border-right: 20px transparent;"
                  "             border-left: 20px transparent;}"
                  "QPushButton:hover{border-image:url(:/img/hover.png);}"
                  "QPushButton:pressed{border-image:url(:/img/press.png);"
                  "                     padding-top:10px;}";


    setStyleSheet(qss);
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << "cool!";
}

void MainWindow::onClick()
{
    QPushButton* button =qobject_cast<QPushButton*>(sender());
    ui->label->setText(QString("%1%2").arg(ui->label->text()).arg(button->text()));
}
