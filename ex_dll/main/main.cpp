#include <QCoreApplication>
#include "mylib.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyLib lib;
    lib.hi();



    return a.exec();
}
