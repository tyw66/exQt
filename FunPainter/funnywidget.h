#ifndef FUNNYWIDGET_H
#define FUNNYWIDGET_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>

namespace Ui {
class FunnyWidget;
}

class FunnyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FunnyWidget(QWidget *parent = 0);
    ~FunnyWidget();


protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent *ev);

private:
    Ui::FunnyWidget *ui;
    QPointF m_mouse;

};

#endif // FUNNYWIDGET_H
