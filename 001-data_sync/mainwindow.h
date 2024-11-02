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


    //----组件A------------------------
private:
    void initConnectA();    //连接组件A的信号槽
private slots:
    void onClickButtonA();  //调用公用模块发信号
    void onReactA(const QString &msg);  //槽函数响应

signals:
    void sigA(const QString& msg);

    //----组件B------------------------
private:
    void initConnectB();
private slots:
    void onClickButtonB();
    void onReactB(const QString &msg);

    //----组件C------------------------
private:
    void initConnectC();
private slots:
    void onChangeListWidget();
    void onReactC(const QString &msg);

    //----组件D------------------------
private:
    void initConnectD();
private slots:
    void onChangeSpinBox(const QString& value);
    void onReactD(const QString &msg);

    //----组件E------------------------
private:
    void initConnectE();
private slots:
    void onChangeComboBox(const QString& value);
    void onReactE(const QString &msg);

    //----组件F------------------------
private:
    void initConnectF();
private slots:
    void onChangeToolBox(int index);
    void onReactF(const QString &msg);

    //----组件G------------------------
private:
    void initConnectG();
private slots:
    void onChangeSliderBar(int index);
    void onReactG(const QString &msg);

    //----组件H------------------------
private:
    void initConnectH();
private slots:
    void onChangeDial(int index);
    void onReactH(const QString &msg);

    //----被动组件1------------------------
private:
    void initConnect1();
private slots:
    void onReact1(const QString &msg);



};
#endif // MAINWINDOW_H
