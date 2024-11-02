#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QUuid>
#include "viewerwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();
    initConnect();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCreateCircle()
{
    Circle * circle = new Circle();
    //    circle->setParameters(QStringList("1"));

    //
    m_dataMap.insert(circle->uid().toString(), circle);

    QListWidgetItem* newItem = new QListWidgetItem(circle->name());
    newItem->setData(Qt::UserRole, circle->uid());
    ui->listWidget->addItem(newItem);
}

void MainWindow::onCreateRectangle()
{
    Rectangle * rect = new Rectangle();
    //    rect->setParameters(QStringList("1"));

    //
    m_dataMap.insert(rect->uid().toString(), rect);

    QListWidgetItem* newItem = new QListWidgetItem(rect->name());
    newItem->setData(Qt::UserRole, rect->uid());
    ui->listWidget->addItem(newItem);
}

void MainWindow::onActiveItem()
{
    QListWidgetItem* item = ui->listWidget->currentItem();
    if(!item){
        return;
    }

    QString uid = item->data(Qt::UserRole).toString();

    if(m_dataMap.contains(uid)){
        Shape* obj = m_dataMap[uid];
        QWidget* w = obj->propertyWidget();
        int index = ui->stackedWidget->indexOf(w);
        if(index == -1){
            ui->stackedWidget->addWidget(w);
            ui->stackedWidget->setCurrentWidget(w);
        }
        else{
            ui->stackedWidget->setCurrentIndex(index);
        }
    }




}

void MainWindow::initUI()
{
    ViewerWidget* v = new ViewerWidget();
    ui->frame_render->layout()->addWidget(v);
}

void MainWindow::initConnect()
{
    connect(ui->actioncircle,&QAction::triggered,
            this, &MainWindow::onCreateCircle);

    connect(ui->actionractangle,&QAction::triggered,
            this, &MainWindow::onCreateRectangle);

    connect(ui->listWidget,&QListWidget::currentRowChanged,
            this, &MainWindow::onActiveItem);
}


