#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include <QVector>

#include<QGraphicsRectItem>
//#include"moneyitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void readInput();

    void calcMoney();

    void drawChart();


private slots:
    void onCalculate();

    void onShowStatusInfo(double value);



private:
    Ui::MainWindow *ui;

    double m_money;  //每期投入金额
    int m_time;             //期数
    double m_rate;          //每期收益率
    bool m_singleFlag;      //是否是只单笔投入

    QGraphicsScene *m_scene;
    QVector<QGraphicsRectItem*> m_items;

    const int m_HEIGHT = 20;
};

#endif // MAINWINDOW_H
