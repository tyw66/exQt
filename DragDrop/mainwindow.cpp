#include "mainwindow.h"
#include<QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    container contain;
    viewer view;

    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(&contain);
    layout->addWidget(&view);
    setLayout(layout);
    setWindowTitle(tr("Drag and Drop"));





}

MainWindow::~MainWindow()
{
}
