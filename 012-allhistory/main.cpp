#include "mainwindow.h"

#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));//中文转码声明

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
