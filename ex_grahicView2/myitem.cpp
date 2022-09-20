#include "myitem.h"

#include <QPainter>
#include <QStyleOptionGraphicsItem>
MyItem::MyItem()
{

}

QRectF MyItem::boundingRect() const
{
    qreal penWidth = 1;
    return QRect(0-penWidth/2, 0-penWidth/2, 100+penWidth/2, 50+penWidth/2);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::DashLine);
    painter->drawEllipse(0,0,50,50);
    painter->translate(-50,0);
    painter->drawEllipse(0,0,100,100);
}
