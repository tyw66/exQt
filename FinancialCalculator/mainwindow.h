#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void drawChart();


private slots:
    void onCalculate();





private:
    Ui::MainWindow *ui;

    double m_money;  //每期投入金额
    int m_time;             //期数
    double m_rate;          //每期收益率
    bool m_singleFlag;      //是否是只单笔投入




};

#endif // MAINWINDOW_H
