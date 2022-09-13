#ifndef FOO1_H
#define FOO1_H
//----------------------------------------------------------------
//方法1：新建一个集成QThread的类，重写虚函数run,通过run启动线程
//----------------------------------------------------------------

#include <QObject>
#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    WorkerThread(QObject* parent = NULL);
    ~WorkerThread();


    bool flag;

private:
    void run() override;



signals:
    void resultReady(const QString &s);
};

#endif // FOO1_H
