#include <QDebug>
#include <QObject>
#include <QThread>
#include <QApplication>
#include <QMainWindow>
#include <QTimer>


class MyWorker : public QObject
{
    Q_OBJECT
public:
    explicit MyWorker(QObject *parent = NULL):QObject(parent){}

signals:
    void finishWork();

public slots:
    void onDowork();

};
void MyWorker::onDowork()
{
    qDebug() << "do work";
    emit finishWork();
}


//class MyThread : public QThread
//{
//    Q_OBJECT
//public:
//    explicit MyThread(QObject *parent = NULL):QThread(NULL){}

//    void run()
//    {
//        qDebug() << "run";
//        exec();
//    }
//};


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    QMainWindow* window = new QMainWindow();
//    window->setWindowTitle("thread");

    MyWorker worker;
    QThread thd;
    QObject::connect(&thd,SIGNAL(started()),&worker,SLOT(onDowork()));
     connect(workerThread, &WorkerThread::finished, workerThread, &QObject::deleteLater);

    thd.start();
//    worker.moveToThread(&thd);

//    window->show();

    return app.exec();
}


