#ifndef EVENTLABEL_H
#define EVENTLABEL_H

#include <QObject>
#include<QLabel>

class EventLabel : public QLabel
{
public:
    EventLabel();

protected:
    void mouseMoveEvent(QMouseEvent *e);
};

#endif // EVENTLABEL_H
