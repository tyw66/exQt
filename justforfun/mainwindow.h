#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    void onTimeout();

    void on_toolButton_logo_pressed();

    void on_toolButton_logo_released();

    void adjustWindow();


private:
    Ui::MainWindow *ui;
    QTimer m_timer;

    QIcon m_icon;
    QIcon m_iconPress;

    bool m_windowExtend;

};
#endif // MAINWINDOW_H
