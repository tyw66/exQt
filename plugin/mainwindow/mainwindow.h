#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainter>

#include "interface.h"

class Mainwindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Mainwindow(QWidget *parent = NULL);

protected:
    void mouseMoveEvent(QMouseEvent* ev);

    void paintEvent(QPaintEvent* ev );
private:
    void renderImg(int x = 0, int y = 0);
    /**
     * @brief 加载插件，填充m_interface对象
     * @return
     */
    bool loadPlugin();
private:
    ImgInterface* m_interface;


    QHBoxLayout*  m_mainLayout;

    QImage m_image;            //帧图像数据
    int mouse_posX, mouse_posY;

    const int W = 256;
    const int H = 256;

};

#endif // DRAWWINDOW_H
