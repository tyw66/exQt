#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include "interface.h"

class Mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Mainwindow(QWidget *parent = NULL);

protected:
    void paintEvent(QPaintEvent* ev );

private:
    bool loadPlugin();

private:
    ImgInterface* m_interface;      //插件接口
    QImage m_image;                  //图像数据

};

#endif // DRAWWINDOW_H
