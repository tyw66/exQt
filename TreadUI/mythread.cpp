#include "mythread.h"

#include"mainwindow.h"



//To create a thread, subclass QThread and reimplement its run() function.
MyThread::MyThread()
{

}

void MyThread::run()
{
    MainWindow::test();
}
