#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initBackground();
    void initFunnyFace();


    QGraphicsItem *buildEye();
    QGraphicsItem *buildEyeBall();
    QGraphicsItem *buildBlush();


    Ui::MainWindow *ui;
    QGraphicsView* view;
    QGraphicsScene* scene;
    QPen borderPen;
};
#endif // MAINWINDOW_H
