#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"container.h"
#include"viewer.h"


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






};







#endif // MAINWINDOW_H
