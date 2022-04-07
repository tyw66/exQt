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

protected:
    void resizeEvent(QResizeEvent *event);

private slots:

    void on_toolButton_clicked();

    void on_toolButton_left_clicked();

    void on_toolButton_right_clicked();

    void refreshButton();

private:
    Ui::MainWindow *ui;

    QWidget *m_ribbonContainer;



};
#endif // MAINWINDOW_H
