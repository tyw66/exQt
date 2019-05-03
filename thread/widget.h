#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include <QToolButton>
#include <QList>

class MyThread : public QThread{
    Q_OBJECT

public:
    explicit MyThread();

public:
    bool m_flag;

protected:
    void run();

signals:
    void sigPlay(double);


private:
    int m_value;


};


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void onPlay(double v);

private:
    Ui::Widget *ui;

    QList<QToolButton*> m_buttons;

    QList<QPointF*> m_points;

    MyThread * m_thread;
    bool m_flag;
    QPoint m_centerPoint;
};

#endif // WIDGET_H
