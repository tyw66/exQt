#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
#include <QStyle>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    m_ribbonContainer = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setMargin(0);

    m_ribbonContainer->setLayout(layout);
    ui->scrollArea->setWidget(m_ribbonContainer);


    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->toolButton_left->setVisible(false);
    ui->toolButton_right->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::resizeEvent(QResizeEvent *event)
{
    refreshButton();
}



void MainWindow::on_toolButton_clicked()
{
    for(int i=0;i<20;++i){
        QToolButton* button = new QToolButton();
        button->setText(QString::number(i));
        button->setIcon(style()->standardIcon((QStyle::StandardPixmap)i));
        button->setIconSize(QSize(164,164));
        button->setToolButtonStyle(Qt::ToolButtonIconOnly);
        m_ribbonContainer->layout()->addWidget(button);

        //       button->setStyleSheet("min-height:30px;max-height:30px;");
    }

    refreshButton();

    QToolButton* bt = new QToolButton();
    bt->setIcon(style()->standardIcon((QStyle::StandardPixmap)0));
    bt->setIcon(QIcon("D:\\123.jpg"));
    bt->setToolButtonStyle(Qt::ToolButtonIconOnly);

    bt->setStyleSheet(""
                      "qproperty-icon:url(D:/1234.jpg);"  //这两行控制图标的路径和大小，等同于setIcon()和setIconSize()
                      "qproperty-iconSize:800px 800px;"
                      "min-height:400px;max-height:400px;" //这两行控制ToolButton本身的大小
                      "min-width:600px;max-width:600px;"
                      "");


    bt->setIconSize(QSize(800,800));
    ui->verticalLayout->addWidget(bt);
}

void MainWindow::on_toolButton_left_clicked()
{
    int value = ui->scrollArea->horizontalScrollBar()->value();
    int step =  ui->scrollArea->width() /2;
    ui->scrollArea->horizontalScrollBar()->setValue(value-step);

    refreshButton();
}

void MainWindow::on_toolButton_right_clicked()
{
    int value = ui->scrollArea->horizontalScrollBar()->value();
    int step =  ui->scrollArea->width() /2;
    ui->scrollArea->horizontalScrollBar()->setValue(value+step);

    refreshButton();

}

void MainWindow::refreshButton()
{
    int a = ui->scrollArea->width();
    int b = m_ribbonContainer->width();
    if(a > b ){
        ui->toolButton_left->setVisible(false);
        ui->toolButton_right->setVisible(false);
    }
    else{
        if(ui->scrollArea->horizontalScrollBar()->value() == 0){
            ui->toolButton_left->setVisible(false);
            ui->toolButton_right->setVisible(true);
        }
        else if(ui->scrollArea->horizontalScrollBar()->value()
                == ui->scrollArea->horizontalScrollBar()->maximum()){
            ui->toolButton_right->setVisible(false);
            ui->toolButton_left->setVisible(true);
        }
        else{
            ui->toolButton_left->setVisible(true);
            ui->toolButton_right->setVisible(true);
        }
    }
}
