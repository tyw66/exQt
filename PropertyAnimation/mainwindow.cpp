#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPropertyAnimation>
#include <QDebug>
#include <QTime>

RainItem::RainItem(const QRectF &rect, QGraphicsItem *parent)
    :QGraphicsEllipseItem(rect,parent)
{

}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initBackground();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initBackground()
{
    //初始化背景与场景
    scene = new QGraphicsScene(this);
    view = new QGraphicsView();
    view->setScene(scene);
    view->setBackgroundBrush(QPixmap(":/bg.jpg"));
//    ui->layout->addWidget(view);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    borderPen.setStyle(Qt::NoPen);
}

//void MainWindow::on_pushButton_clicked()
//{
//    ////    for(int i=0;i<10;i++){
//    //        QPushButton *button = new QPushButton("rain",this);
//    //        button->show();
//    //        int posX = qrand()%width();

//    //        QPropertyAnimation* animation=new QPropertyAnimation(ui->pushButton_2, "geometry");
//    //        animation->setDuration(200);
//    //        qDebug() <<posX;

//    //        animation->setStartValue(QRect(120,60,200,100));
//    //        animation->setEndValue(QRect(120,60,200,0));

//    ////        animation->setEasingCurve(QEasingCurve::InQuad);

//    //        animation->start();
//    ////    }


//    int posX = qrand()%width();
//    RainItem *rain = new RainItem(QRect(posX,0,10,20));

//    rain->setBrush(QBrush(QColor(77, 51, 25)));
//    rain->setPen(borderPen);
//    scene->addItem(rain);

//    QPropertyAnimation* animation=new QPropertyAnimation(rain, "posTYW");
//    animation->setDuration(1000);
//    animation->setStartValue(QPointF(posX,0));
//    animation->setEndValue(QPointF(posX,500));

//    //        animation->setEasingCurve(QEasingCurve::InQuad);

//    animation->start();
//}



