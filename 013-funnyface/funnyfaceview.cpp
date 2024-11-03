#include "funnyfaceview.h"
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsEllipseItem>

FunnyFaceView::FunnyFaceView()
{
    setBackgroundBrush(QPixmap(":/image/bg.jpg"));
    setDragMode(QGraphicsView::ScrollHandDrag);
    setMouseTracking(true);
    // m_borderPen.setStyle(Qt::NoPen);
    m_borderPen.setWidth(4);
}

void FunnyFaceView::initFace()
{
    //脸
    QGraphicsEllipseItem *faceItem = new QGraphicsEllipseItem(QRect(0,0,500,500));
    faceItem->setBrush(QBrush(QColor(250,233,161)));
    faceItem->setPen(m_borderPen);
    scene()->addItem(faceItem);

    //左右眼眶
    QGraphicsItem * leftEye = buildEye();
    QGraphicsItem * rightEye = buildEye();
    scene()->addItem(leftEye);
    scene()->addItem(rightEye);

    leftEye->moveBy(0,160);
    rightEye->moveBy(300,160);

    //左右眼珠
    m_leftEyeBall = buildEyeBall();
    m_rightEyeBall = buildEyeBall();
    scene()->addItem(m_leftEyeBall);
    scene()->addItem(m_rightEyeBall);

    m_leftEyeBall->moveBy(100,160);
    m_rightEyeBall->moveBy(400,160);

    //左右腮红
    QGraphicsItem *leftBlashItem = buildBlush();
    QGraphicsItem *rightBlashItem = buildBlush();
    scene()->addItem(leftBlashItem);
    scene()->addItem(rightBlashItem);

    leftBlashItem->moveBy(10,220);
    rightBlashItem->moveBy(400,220);
}

QGraphicsItem *FunnyFaceView::buildEye()
{
    QVector<QPointF> borderPoints;
    borderPoints << QPoint(10,0) << QPoint(190,0)<< QPoint(200,10)<< QPoint(200,30)
                 << QPoint(190,40)<< QPoint(10,40)<< QPoint(0,30)<< QPoint(0,10);

    //眼眶
    QGraphicsPolygonItem *eyeItem = new QGraphicsPolygonItem();
    eyeItem->setPolygon(QPolygonF(borderPoints));

    eyeItem->setBrush(QBrush(QColor(255,255,255)));
    eyeItem->setPen(m_borderPen);

    return eyeItem;
}

QGraphicsItem *FunnyFaceView::buildEyeBall()
{
    //眼球
    QGraphicsEllipseItem *eyeBallItem = new QGraphicsEllipseItem(QRect(0,0,40,40));

    eyeBallItem->setBrush(QBrush(QColor(77, 51, 25)));
    eyeBallItem->setPen(m_borderPen);

    return eyeBallItem;
}

QGraphicsItem *FunnyFaceView::buildBlush()
{
    //腮红
    QGraphicsEllipseItem *blashItem = new QGraphicsEllipseItem(QRect(0,0,100,30));

    blashItem->setBrush(QBrush(QColor(255, 230, 204)));
    blashItem->setPen(m_borderPen);

    return blashItem;
}


void FunnyFaceView::mouseMoveEvent(QMouseEvent *event)
{
    double xFactor = event->localPos().x() / width();
    // double yFactor = event->localPos().y() / height();

    //眼睛随鼠标左右动
    QPointF posLeftEyeBall = m_leftEyeBall->pos();
    QPointF posRightEyeBall = m_rightEyeBall->pos();

    posLeftEyeBall.setX(160.0 * xFactor);
    posRightEyeBall.setX(160.0 * xFactor + 300.0);


    m_leftEyeBall->setPos(posLeftEyeBall);
    m_rightEyeBall->setPos(posRightEyeBall);


    // // 创建一个旋转矩阵，以 centerPoint 为旋转中心
    // QTransform transform;
    // QPointF center = scene()->sceneRect().center();
    // transform.translate(center.x(), center.y()); // 移动到旋转中心
    // transform.rotate(yFactor * 360 - 180); // 旋转
    // transform.translate(-center.x(), -center.y()); // 移动回原位置（相对于旋转中心）


    // // 遍历场景中的所有项目
    // QList<QGraphicsItem*> items = scene()->items();
    // for (QGraphicsItem* item : items) {
    //     if (item) {
    //         // 获取当前的变换矩阵
    //         QTransform currentTransform = item->transform();

    //         // 将当前的变换矩阵与旋转矩阵组合
    //         QTransform combinedTransform = currentTransform * transform;

    //         // 应用变换矩阵
    //         item->setTransform(combinedTransform, false); // true 表示组合变换
    //     }
    // }
}
