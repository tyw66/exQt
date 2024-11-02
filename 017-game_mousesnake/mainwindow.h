#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QPointF>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


private slots:
    void on_pushButton_clicked();

private:
    void updateData(const QPointF &pos);
    void genDizzert();



private:
    Ui::MainWindow *ui;
    QTimer m_timer;

    QVector<QPointF> m_pointList;


    bool m_playing;

    static int score;
    QPointF m_dizzert;

};
#endif // MAINWINDOW_H
