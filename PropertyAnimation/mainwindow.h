#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class RainItem : public QObject , public QGraphicsEllipseItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF posTYW READ pos WRITE setPos)
public:
    RainItem(const QRectF &rect, QGraphicsItem *parent = nullptr);



};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void on_pushButton_clicked();

private:
    void initBackground();

private:
    Ui::MainWindow *ui;

    QGraphicsView* view;
    QGraphicsScene* scene;
    QPen borderPen;
};
#endif // MAINWINDOW_H
