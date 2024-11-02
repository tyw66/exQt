#include "viewerwidget.h"
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
ViewerWidget::ViewerWidget(QWidget *parent) : QWidget(parent)
{


}

void ViewerWidget::paintEvent(QPaintEvent *event)
{
    qDebug() << __FUNCTION__;

    QPainter painter(this);

    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect(), Qt::AlignCenter, "Qt");

}
