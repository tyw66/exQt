#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QTime>
#include <QDebug>
#include <QRandomGenerator>
#include <QToolButton>
#include <QPropertyAnimation>
#include <QSharedPointer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //
    ui->setupUi(this);
    setWindowFlag(Qt::WindowStaysOnTopHint);

    //确定随机显示的图片
    int picIndex = QRandomGenerator::global()->generate()%10+1;
    qDebug() << picIndex;
    QString picPath =QString(":/res/pic_%1.jpg").arg(picIndex);

    QPixmap pixmap(picPath);
    m_icon.addPixmap(pixmap,QIcon::Normal,QIcon::On);

    //确定按钮按下去显示的图片（固定）
    QPixmap pixmapPress(":/res/press.png");
    m_iconPress.addPixmap(pixmapPress,QIcon::Normal,QIcon::On);

    //为按钮设置图片
    ui->toolButton_logo->setIconSize(ui->toolButton_logo->size());
    ui->toolButton_logo->setIcon(m_icon);



    //显示时间
    ui->lcdNumber_time->display(QTime().currentTime().toString());

    m_timer.setInterval(1000);
    connect(&m_timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
    m_timer.start();

    setWindowFlag(Qt::FramelessWindowHint);
    m_windowExtend = false;

    connect(ui->toolButton_quit,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(ui->toolButton_adjust,SIGNAL(clicked()),this,SLOT(adjustWindow()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeout()
{
    QTime t;

    ui->lcdNumber_time->display(t.currentTime().toString());
}


void MainWindow::on_toolButton_logo_pressed()
{
    ui->toolButton_logo->setIcon(m_iconPress);
}

void MainWindow::on_toolButton_logo_released()
{
    ui->toolButton_logo->setIcon(m_icon);
}

void MainWindow::adjustWindow()
{
    int x = geometry().x();
    int y = geometry().y();


//    QSharedPointer<QPropertyAnimation> anim =
//            QSharedPointer<QPropertyAnimation>(new QPropertyAnimation(this,"geometry"));

    QPropertyAnimation* anim =new QPropertyAnimation(this,"geometry");
    if(m_windowExtend){
        ui->toolButton_adjust->setText("-");
        anim->setDuration(100);
        anim->setStartValue(QRect(x, y, 700, 200));
        anim->setEndValue(QRect(x, y, 460, 130));
    }
    else{
        ui->toolButton_adjust->setText("+");
        anim->setDuration(100);
        anim->setStartValue(QRect(x, y, 460, 130));
        anim->setEndValue(QRect(x, y, 700, 200));
    }
    m_windowExtend = !m_windowExtend;
    anim->start();

}

