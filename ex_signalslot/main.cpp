#include "widget.h"
#include <QApplication>
#include <QMetaEnum>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
   qDebug() <<  w.metaObject()->enumerator(0).key(1);
    w.show();

    return a.exec();
}
