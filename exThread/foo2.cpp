#include "foo2.h"
#include <QTime>

Foo2::Foo2()
{

}

void Foo2::onClock()
{
    while(true){
        QString time = QString("%1:%2:%3")
                .arg(QTime::currentTime().hour(),2,10,QLatin1Char('0'))
                .arg(QTime::currentTime().minute(),2,10,QLatin1Char('0'))
                .arg(QTime::currentTime().second(),2,10,QLatin1Char('0'));

        emit resultReady(time);
    }
}
