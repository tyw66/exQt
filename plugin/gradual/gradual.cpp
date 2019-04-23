#include "gradual.h"
#include <QtPlugin>
#include <QColor>

Gradual::Gradual(QObject *parent)
{
}

void Gradual::paintImg(QImage &img)
{
    int w = img.width();
    int h = img.height();

//#pragma omp parallel for
    //遍历像素点
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            //获取颜色
            int r = 255*i/h;//+55*x/h;
            //设置颜色
            img.setPixel(j,i,QColor::fromRgb(r, 160,160).rgb());
        }
    }

}


//导出该插件 （插件名，插件类名）
Q_EXPORT_PLUGIN2(gradual,Gradual)
