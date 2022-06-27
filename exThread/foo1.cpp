#include "foo1.h"
#include <QTimer>
#include <QDebug>

void WorkerThread::run() {
    QString result = "res";
    //长耗时操作
    int a = 0;
    while(a < 100000){
        a++;
        qDebug()<< a;
    }
    emit resultReady(result);
}
