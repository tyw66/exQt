#include "widget.h"
#include "ui_widget.h"
#include <math.h>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_thread = new MyThread();
    m_flag = false;
    connect(m_thread, SIGNAL(sigPlay(double)), this, SLOT(onPlay(double)));

    //初始化标签
    for(int i = 0 ; i < 80; ++i){
        QToolButton *button = new QToolButton(this);
        m_buttons.append(button);
        button->setStyleSheet(QString("background:rgb(%1,%2,%3);border:none;").arg(0).arg(i+128).arg(255));
        button->move(width()/2 - button->width()/2, height()/2 - button->height()/2);
        button->setFixedHeight(20);
        button->setFixedWidth(20);
        m_centerPoint = QPoint(width()/2 - button->width()/2, height()/2 - button->height()/2);
    }
    qDebug() << "m_centerPoint x:"<<m_centerPoint.x()<<" m_centerPoint.y:"<<m_centerPoint.y() ;


    //计算标签终止位置 - 圆
    for(int i = 0 ; i < 40; ++i){
        int x = width()/40 * i;
        double temp = sqrt(500*500 - (x - width()/2) * (x - width()/2));
        int y1 = temp + height() / 2;
        int y2 = -temp + height() / 2;
        m_points.append(new QPointF(x, y1));
        m_points.append(new QPointF(x, y2));
        qDebug() << "x:"<<x<<" y1:"<<y1<<" y2:"<<y2 ;
    }

    //计算标签终止位置 - 心型线
//    for(double x = -1 ; x < 1; x+=0.025){
//        //        int x = width()/40 * i;
//        double temp = sqrt(1-x*x+0.25*pow(x,4/3));
//        //        qDebug() << "temp:"<<temp ;
//        int y1 = temp + 0.5 * pow(x, 0.666);
//        int y2 = -temp + 0.5 * pow(x, 0.666);
//        m_points.append(new QPointF(x, y1));
//        m_points.append(new QPointF(x, y2));
//        qDebug() << "x:"<<x<<" y1:"<<y1<<" y2:"<<y2 ;
//    }

    for(int i = 0; i < 360; i++){
        double rad = i/180*3.14;
        double x = 10 * (1 + cos(rad)) * cos(rad);
        double y = 10 * (1 + cos(rad)) * sin(rad);
        m_points.append(new QPointF(x, y));
    }

}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_clicked()
{
    if(m_flag){
        m_thread->m_flag = false;
        m_thread->exit();
    }
    else{
        m_thread->m_flag = true;
        m_thread->start();
    }
    m_flag= !m_flag;
}


void Widget::onPlay(double v)
{
    QString qss = QString("background:rgb(%1,%2,%3)").arg(255 - v*50).arg(255 - v * 50).arg(255 - v*50);
    setStyleSheet(qss);

    qDebug() << v;
    for(int i = 0 ; i < 80; ++i){
        int x = m_centerPoint.x() + (m_points.at(i)->x() - m_centerPoint.x()) * v ;
        int y = m_centerPoint.y() + (m_points.at(i)->y() - m_centerPoint.y()) * v ;

        m_buttons.at(i)->move(QPoint(x,y));

        qDebug() << "x:"<<x<<" y:"<<y;
    }

}



MyThread::MyThread()
{
    m_value = 0;
}

void MyThread::run()
{
    while(m_flag){
        //        if(m_value > 255)
        //            m_value = 0;
        emit sigPlay(0.3 * sin(0.5 * m_value++) + 0.5);
        msleep(100);
    }
}
