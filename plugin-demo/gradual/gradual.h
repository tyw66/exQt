#ifndef FUNNYWIDGET_H
#define FUNNYWIDGET_H

#include <QObject>
#include "interface.h"

class Gradual : public QObject, public ImgInterface
{
    Q_OBJECT
    Q_INTERFACES(ImgInterface)//告知Qt，这个类实现了哪个接口
public:
    explicit Gradual(QObject *parent = NULL);

    void paintImg(QImage& img);

};

#endif // FUNNYWIDGET_H
