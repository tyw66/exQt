#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //bool值与int值转换
    bool flagF = false, flagT = true;
    qDebug()<< QString("true to int is :%1").arg(flagT);    //"true to int is :1"
    qDebug()<< QString("false to int is :%1").arg(flagF);   //"false to int is :0"



    return a.exec();
}
