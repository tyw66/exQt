#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



#include "progressbar.h"

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
    void on_pushButton_a_clicked();
    void on_pushButton_b_clicked();

private:
    Ui::MainWindow *ui;

    ProgressBar* m_progressView;

    //长耗时工作
    void workA();
    void workB();





private slots:
    //长耗时工作后的工作
    void postWorkA();
    void postWorkB();

};
#endif // MAINWINDOW_H
