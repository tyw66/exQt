#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "foo1.h"
#include "foo2.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onShowResult(QString);



    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();



    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

signals:
    void startIt();

private:
    Ui::MainWindow *ui;

    WorkerThread* m_stopWatch;

    QThread* m_thread;
    Foo2 foo;

};





#endif // MAINWINDOW_H
