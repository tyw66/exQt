#include "eventlabel.h"
#include<QMouseEvent>

EventLabel::EventLabel()
{
    setMouseTracking(true);
}

void EventLabel::mouseMoveEvent(QMouseEvent *e)
{
    this->setText(tr("x:%1, y:%2").arg(e->x()).arg(e->y()));
}
