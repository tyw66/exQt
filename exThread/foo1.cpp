#include "foo1.h"
#include <QTimer>
#include <QDebug>
#include <QTime>

WorkerThread::WorkerThread(QObject *parent)
{
    flag = false;
}

WorkerThread::~WorkerThread()
{
    qDebug() << "~WorkerThread():" << this;
}

void WorkerThread::run() {
    QString result = "res";
    //长耗时操作
    while(flag){
        QString time = QString("%1:%2:%3")
                .arg(QTime::currentTime().hour(),2,10,QLatin1Char('0'))
                .arg(QTime::currentTime().minute(),2,10,QLatin1Char('0'))
                .arg(QTime::currentTime().second(),2,10,QLatin1Char('0'));

        emit resultReady(time);
        msleep(1000);


//        static int value = 100;
//        msleep(1000);
//        value+=10;
//        emit resultReady(QString::number(value%100));
    }
    //    exec();
}
