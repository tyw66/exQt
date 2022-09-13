#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initBackground();
    initFunnyFace();

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
    ui->layout->addWidget(view);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    borderPen.setStyle(Qt::NoPen);
}

void MainWindow::initFunnyFace()
{
    //脸
    QGraphicsEllipseItem *faceItem = new QGraphicsEllipseItem(QRect(0,0,500,500));
    faceItem->setBrush(QBrush(QColor(250,233,161)));
    faceItem->setPen(borderPen);
    scene->addItem(faceItem);

    //左右眼眶
    QGraphicsItem * leftEye = buildEye();
    leftEye->moveBy(0,160);
    QGraphicsItem * rightEye = buildEye();
    rightEye->moveBy(300,160);

    scene->addItem(leftEye);
    scene->addItem(rightEye);

    //左右眼珠
    QGraphicsItem * leftEyeBall = buildEyeBall();
    leftEyeBall->moveBy(10,160);
    QGraphicsItem * rightEyeBall = buildEyeBall();
    rightEyeBall->moveBy(310,160);

    scene->addItem(leftEyeBall);
    scene->addItem(rightEyeBall);

    //左右腮红
    QGraphicsItem *leftBlashItem = buildBlush();
    leftBlashItem->moveBy(10,220);
    QGraphicsItem *rightBlashItem = buildBlush();
    rightBlashItem->moveBy(400,220);

    scene->addItem(leftBlashItem);
    scene->addItem(rightBlashItem);
}



QGraphicsItem *MainWindow::buildEye()
{
    QVector<QPointF> borderPoints;
    borderPoints << QPoint(10,0)
                 << QPoint(190,0)
                 << QPoint(200,10)
                 << QPoint(200,30)
                 << QPoint(190,40)
                 << QPoint(10,40)
                 << QPoint(0,30)
                 << QPoint(0,10);

    //眼眶
    QGraphicsPolygonItem *eyeItem = new QGraphicsPolygonItem();
    eyeItem->setPolygon(QPolygonF(borderPoints));

    eyeItem->setBrush(QBrush(QColor(255,255,255)));
    eyeItem->setPen(borderPen);

    return eyeItem;
}

QGraphicsItem *MainWindow::buildEyeBall()
{
    //眼球
    QGraphicsEllipseItem *eyeBallItem = new QGraphicsEllipseItem(QRect(0,0,40,40));

    eyeBallItem->setBrush(QBrush(QColor(77, 51, 25)));
    eyeBallItem->setPen(borderPen);

    return eyeBallItem;
}

QGraphicsItem *MainWindow::buildBlush()
{
    //腮红
    QGraphicsEllipseItem *blashItem = new QGraphicsEllipseItem(QRect(0,0,100,30));

    blashItem->setBrush(QBrush(QColor(255, 230, 204)));
    blashItem->setPen(borderPen);

    return blashItem;
}

