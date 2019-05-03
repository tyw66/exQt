#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class IconEdit : public QWidget
{
  Q_OBJECT
  Q_PROPERTY(QColor penColor READ penColor WRITE setPenColor)
  Q_PROPERTY(QImage iconImage READ iconImage WRITE setIconImage)
  Q_PROPERTY(int zoomFactor READ zoomFactor WRITE setZoomFactor)

public:
  IconEdit(QWidget *parent = 0);

  QColor penColor()const{return curColor;}
  void setPenColor(const QColor &newColor);

  QImage iconImage()const{return image;}
  void setIconImage(const QImage &newImage);

  void setZoomFactor(int newZoom);
  int zoomFactor()const{return zoom;}

  QSize sizeHint() const;

protected:
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void paintEvent(QPaintEvent *event);


private:
  QColor curColor;
  QImage image;
  int zoom;

  void setImagePixel(const QPoint &pos,bool opaque);
  QRect pixelRect(int i,int j)const;

};

#endif // WIDGET_H
