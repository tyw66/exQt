#ifndef FUNNYFACEVIEW_H
#define FUNNYFACEVIEW_H
#include <QGraphicsView>

/**
 * @brief 显示滑稽表情
 */
class FunnyFaceView : public QGraphicsView
{
public:
    FunnyFaceView();
    void initFace();

protected:
    void extracted(double &yFactor, QList<QGraphicsItem *> &items);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QGraphicsItem *buildEye();
    QGraphicsItem *buildEyeBall();
    QGraphicsItem *buildBlush();

private:
    QGraphicsItem * m_leftEyeBall;
    QGraphicsItem * m_rightEyeBall;
    QPen m_borderPen;

};

#endif // FUNNYFACEVIEW_H
