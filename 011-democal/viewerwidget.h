#ifndef VIEWERWIDGET_H
#define VIEWERWIDGET_H

#include <QWidget>

class ViewerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ViewerWidget(QWidget *parent = nullptr);



protected:
    void paintEvent(QPaintEvent *event);


};

#endif // VIEWERWIDGET_H
