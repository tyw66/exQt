#include "widget.h"
#include<QPainter>
#include<QPaintEvent>

IconEdit::IconEdit(QWidget *parent)
  : QWidget(parent)
{
  setAttribute(Qt::WA_StaticContents);
  setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);

  curColor=Qt::black;
  zoom=10;
  image=QImage(20,20,QImage::Format_ARGB32);
  image.fill(qRgba(0,0,0,0));

}

void IconEdit::setPenColor(const QColor &newColor)
{
  curColor=newColor;
}

void IconEdit::setIconImage(const QImage &newImage)
{
  if(newImage!=image)
    {
      image=newImage.convertToFormat(QImage::Format_ARGB32);
      update();
      updateGeometry();
    }
}

void IconEdit::setZoomFactor(int newZoom)
{
  if(newZoom<1)
    newZoom=1;

  if(newZoom!=zoom)
    {
     zoom=newZoom;
     update();
     updateGeometry();
    }
}

QSize IconEdit::sizeHint() const
{
  QSize size=zoom*image.size();
  if(zoom>=3)
    size+=QSize(1,1);
  return size;
}

void IconEdit::mousePressEvent(QMouseEvent *event)
{
  if(event->button()==Qt::LeftButton)
    {
      setImagePixel(event->pos(),true);
    }
  else if(event->button()==Qt::RightButton)
    {
      setImagePixel(event->pos(),false);
    }
}

void IconEdit::mouseMoveEvent(QMouseEvent *event)
{
  if(event->buttons()&Qt::LeftButton)
    {
      setImagePixel(event->pos(),true);
    }
  else if(event->buttons()&Qt::RightButton)
    {
      setImagePixel(event->pos(),false);
    }
}

void IconEdit::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  if(zoom>=3)
  {
      painter.setPen(palette().foreground().color());
      for(int i=0;i<=image.width();++i)
        painter.drawLine(zoom*i,0,zoom*i,zoom*image.height());
      for(int j=0;j<=image.height();++j)
        painter.drawLine(0,zoom*j,zoom*image.width(),zoom*j);
    }

  for(int i=0;i<image.width();++i)
      for(int j=0;j<image.width();++j)
    {
      QRect rect =pixelRect(i,j);
      if(!event->region().intersects(rect))
        {
          QColor color=QColor::fromRgba(image.pixel(i,j));
          if(color.alpha()<255)
            painter.fillRect(rect,color);
          painter.fillRect(rect,color);
        }
    }



}

void IconEdit::setImagePixel(const QPoint &pos, bool opaque)
{
  int i=pos.x()/zoom;
  int j=pos.y()/zoom;
  if(image.rect().contains(i,j))
    {
      if(opaque)
        {
         image.setPixel(i,j,penColor().rgb());
        }
      else
        {
         image.setPixel(i,j,qRgba(0,0,0,0));
        }
      update(pixelRect(i,j));
    }


}

QRect IconEdit::pixelRect(int i, int j) const
{
  if(zoom>=3)
    {
      return QRect(zoom*i+1,zoom*j+1,zoom-1,zoom-1);
    }
  else
    {
      return QRect(zoom*i,zoom*j,zoom,zoom);
    }
}


