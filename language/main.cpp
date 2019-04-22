#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include<QTranslator>
#include <QLocale>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //识别本地语言环境
    qDebug() << QLocale::system().name();//"zh-CN";""
    QLocale::Language language = QLocale::system().language();//语言
    //QLocale::Country country =  QLocale::system().country();//国家

    //加载翻译文件
    QTranslator translator;
    switch (language) {
    case QLocale::Chinese:{
        translator.load("./zh-cn.qm");
        break;
    }
    case QLocale::English:{
        translator.load("./en-us.qm");
        break;
    }
    case QLocale::Japanese:{
        translator.load("./ja-jp.qm");
        break;
    }
    default:
        break;
    }

    //安装翻译器
    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
