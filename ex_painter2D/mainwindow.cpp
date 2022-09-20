#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include <QDateTime>
#include <QRandomGenerator>

int MainWindow::score = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    m_playing = false;
    genDizzert();

    //    m_timer.setInterval(50);
    //    connect(&m_timer,SIGNAL(timeout()),this,SLOT(update()));
    //    m_timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPen pen;
    QPainter painter(this);

    pen.setWidth(10);

    //画蛇
    pen.setStyle(Qt::SolidLine);
    pen.setColor(QColor(125,200,30));
    painter.setPen(pen);
    painter.drawLines(m_pointList);

    //画食物
    pen.setStyle(Qt::SolidLine);
    pen.setColor(QColor(255,100,30));
    painter.setPen(pen);
    painter.drawPoint(m_dizzert);

}




void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(m_playing){
        QPointF mousePt = event->pos();
        if((mousePt-m_dizzert).manhattanLength()<10){
            score++;
            ui->label_score->setText(QString::number(score));
            genDizzert();
        }

        updateData(mousePt);
    }
}

void MainWindow::updateData(const QPointF& pos)
{
    //如果这个点距离现有的点太近就不加入到长度中
    if(!m_pointList.empty()){
        if((pos-m_pointList.front()).manhattanLength()<9){
            return;
        }
    }

    //加入到现有长度中
    m_pointList.push_front(pos);
    while(m_pointList.size()>score*2+10){
        m_pointList.pop_back();
    }

    update();
}

void MainWindow::genDizzert()
{
    quint32 seed = quint32(QDateTime::currentDateTime().toSecsSinceEpoch());
    QRandomGenerator generator(seed);

    m_dizzert.setX(generator.bounded(0, width()));
    m_dizzert.setY(generator.bounded(0, height()));
}




void MainWindow::on_pushButton_clicked()
{
    if(!m_playing){
        m_playing=true;
        ui->pushButton->setText("stop");
    }
    else{
        m_playing=false;
        ui->pushButton->setText("go");
        m_pointList.clear();
        update();
    }
}
