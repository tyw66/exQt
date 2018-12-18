/** **********************************
* @brief QImage
*
* @date 2018.02.08
* @author tyw66
*************************************/
#include<QApplication>
#include<QWidget>
#include<QPainter>
#include<math.h>

#define IMG_SIZE 256
#define WND_SIZE 1080

class ImageFrom : public QWidget{
public:
    ImageFrom();
//    ~PictureFrom();

protected:
    void paintEvent(QPaintEvent *e);

    QImage I_WANT_A_PICTURE(int width, int height);
};

ImageFrom::ImageFrom()
{
    resize(WND_SIZE,WND_SIZE);
}

void ImageFrom::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QImage img = I_WANT_A_PICTURE(IMG_SIZE,IMG_SIZE);
    QPainter p;
    p.begin(this);
    p.drawImage(QRect(0,0,WND_SIZE,WND_SIZE),img);
    p.end();
}

///填充此函数获得不同图像
QImage ImageFrom::I_WANT_A_PICTURE(int width, int height)
{
    QImage image(width,height,QImage::Format_RGB32);
    int r,g,b;
    for(int j=0;j<height;++j){
        for(int i=0;i<width;++i){
            r = g = b= abs(sin(i*j)*256);
            image.setPixel(i,j,qRgb(r,g,b));
        }
    }
    return image;
}


int main(int argc, char* argv[]){
    QApplication app(argc,argv);
    ImageFrom form;
    form.show();
    return app.exec();
}
