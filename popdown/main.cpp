#include "toydialog.h"
#include <QApplication>

#include <QTextCodec>
#include <QVariant>

#include<QUuid>
#include<QDebug>
int main(int argc, char *argv[])
{

    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));

    QApplication a(argc, argv);
    ToyDialog w;
    w.show();


    return a.exec();
}
