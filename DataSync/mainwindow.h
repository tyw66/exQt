#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


    //----A------------------------
private:
    void initConnectA();    //连接组件A的信号槽
private slots:
    void onClickButtonA();  //调用公用模块发信号
    void onReactA(const QString &msg);  //槽函数响应

    //----B------------------------
private:
    void initConnectB();
private slots:
    void onClickButtonB();
    void onReactB(const QString &msg);

    //----C------------------------
private:
    void initConnectC();
private slots:
    void onClickButtonC();
    void onReactC(const QString &msg);


    //----D------------------------
private:
    void initConnectD();
private slots:
    void onClickButtonD();
    void onReactD(const QString &msg);


};
#endif // MAINWINDOW_H
