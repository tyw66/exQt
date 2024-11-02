#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MyLabel : public QLabel{
    Q_OBJECT
public:
    MyLabel(){
        setText("MyLabel");
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onApplyStyleSheet();

    void onMkCommon();
    void onMkMainWindow();
    void onMkDialog();
    void onMkMdiArea();
    void onMkMdiSubWindow();
    void onMkDockWidget();
    void onMkStatusBar();
    void onMkMenuBar();
    void onMkMenu();



private:
    Ui::MainWindow *ui;

    QColor m_color01 = QColor("#FAFAFA");
    QColor m_color02 = QColor("#3C3C3C");
    QColor m_color03 = QColor("#888888");
    QColor m_color04 = QColor("#333333");
    QColor m_color05 = QColor("#111111");
    QColor m_color06 = QColor("#A05B00");
    QColor m_color06_1 = QColor("#555555");
    QColor m_color06_2 = QColor("#A05B00");
    QColor m_color07 = QColor("#404040");
    QColor m_color08 = QColor("#555555");
    QColor m_color09 = QColor("#606060");
    QColor m_color10 = QColor("#535353");
    QColor m_color11 = QColor("#BBBBBB");

};
#endif // MAINWINDOW_H
