#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "skinwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initUI()
{
    SkinWidget* skinWidget = new SkinWidget();
    ui->layout_skin->addWidget(skinWidget);


    ui->toolButton_A->setIcon(QIcon(":/icons/save.png"));
    ui->toolButton_B->setIcon(QIcon(":/icons/close_project.png"));
    ui->toolButton_A->setIconSize(QSize(48,48));
    ui->toolButton_B->setIconSize(QSize(48,48));
}

