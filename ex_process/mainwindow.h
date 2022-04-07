#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    bool on_pushButton_notepad_clicked();

    void on_show_result();

    void on_show_status(QProcess::ProcessState state);

    void on_show_error();

private:
    Ui::MainWindow *ui;
    QProcess m_process;
};

#endif // MAINWINDOW_H
