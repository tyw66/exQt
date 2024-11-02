#include "funnywidget.h"
#include "ui_funnywidget.h"
#include <QPainter>


FunnyWidget::FunnyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FunnyWidget)
{
    ui->setupUi(this);
    setMouseTracking(true);


}

FunnyWidget::~FunnyWidget()
{
    delete ui;
}

void FunnyWidget::mouseMoveEvent(QMouseEvent *ev)
{
    m_mouse.setX((double)ev->pos().x()/width());
    m_mouse.setY((double)ev->pos().y()/height());

    update();
}

#include <QLinearGradient>
void FunnyWidget::paintEvent(QPaintEvent *ev)
{
    //渐变填充
//    m_mouse*=500;
//    QLinearGradient gradient(QPoint(500,500)-m_mouse, m_mouse);
//    gradient.setColorAt(0, Qt::white);
//    gradient.setColorAt(1, Qt::darkGray);


    //脸
    QPainter painter;
    painter.begin(this);
    painter.setPen(Qt::black);
//    painter.setBrush(gradient);
    painter.drawEllipse(QPoint(250,250), 200,200);

    //鼻子
    painter.setPen(Qt::darkGray);
    painter.setBrush(Qt::gray);
    painter.drawEllipse(QPoint(250,250), 18,10);


//    painter.translate();

    painter.end();
}
