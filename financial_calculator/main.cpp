#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //安装翻译器
    QTranslator translator;
    translator.load("./zh_cn.qm");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}
