#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化背景与场景
    scene = new QGraphicsScene(this);
    view = new MyView();
    view->setScene(scene);
    view->setBackgroundBrush(QPixmap(":/bg.jpg"));
    ui->layout->addWidget(view);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    borderPen.setStyle(Qt::NoPen);

    MyItem* item =new MyItem();
    scene->addItem(item);


    QHBoxLayout* hLayout = new QHBoxLayout(view);
    view->setLayout(hLayout);
    QPushButton* button = new QPushButton(view);
    hLayout->addWidget(button);

}

MainWindow::~MainWindow()
{
    delete ui;
}

