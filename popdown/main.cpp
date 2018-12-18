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

//QUuid id0=QUuid::createUuid();
//qDebug()<<id0.toString();
//QUuid test(id0.toString());
//qDebug()<<test;


/*
QUuid id1=QUuid::createUuid();
QUuid id2=QUuid::createUuid();
QUuid id3=QUuid::createUuid();
QUuid id4=QUuid::createUuid();
QUuid id5=QUuid::createUuid();
QUuid id6=QUuid::createUuid();
qDebug()<<id1;
qDebug()<<id2;
qDebug()<<id3;
qDebug()<<id4;
qDebug()<<id5;
qDebug()<<id6;
*/
    return a.exec();
}
