#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 初始化背景与场景
    m_scene = new QGraphicsScene(this);
    m_view = new FunnyFaceView();
    m_view->setScene(m_scene);
    ui->layout->addWidget(m_view);

    //画脸
    m_view->initFace();

}

MainWindow::~MainWindow()
{
    delete ui;
}




