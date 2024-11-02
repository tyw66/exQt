#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "objects.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void onCreateCircle();
    void onCreateRectangle();

    void onActiveItem();


private:
    void initUI();
    void initConnect();

private:
    Ui::MainWindow *ui;

    QMap<QString, Shape*> m_dataMap;

};

#endif // MAINWINDOW_H
