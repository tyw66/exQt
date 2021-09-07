#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "signalhub.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    initConnectA();
    initConnectB();
    initConnectC();
    initConnectD();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//--组件A--
void MainWindow::initConnectA()
{
    connect(ui->pushButtonA, SIGNAL(clicked()),this,SLOT(onClickButtonA()));
    connect(SignalHub::inst(),SIGNAL(currentSelectIDChanged(int)),this,SLOT(onReactA(int)));
}

void MainWindow::onClickButtonA()
{
    int id = ui->textEditA->toPlainText().toInt();
    SignalHub::inst()->emitCurrentSelectIDChanged(id);//Qt4
//    emit Common::inst()->currentSelectIDChanged(id);//Qt5

}

void MainWindow::onReactA(int id)
{
    ui->textEditA->clear();
    ui->textEditA->setPlainText(QString::number((id)));
}

//--组件B--
void MainWindow::initConnectB()
{
    connect(ui->pushButtonB, SIGNAL(clicked()),this,SLOT(onClickButtonB()));
    connect(SignalHub::inst(),SIGNAL(currentSelectIDChanged(int)),this,SLOT(onReactB(int)));
}

void MainWindow::onClickButtonB()
{
    int id = ui->listWidgetB->currentItem()->text().toInt();
    SignalHub::inst()->emitCurrentSelectIDChanged(id);
}

void MainWindow::onReactB(int id)
{
    QList<QListWidgetItem*> list = ui->listWidgetB->findItems(QString::number(id),Qt::MatchExactly);
    ui->listWidgetB->setCurrentRow(-1);//取消选择
    if(!list.isEmpty()){
        ui->listWidgetB->setCurrentItem(list.first());
    }
}

//--组件C--
void MainWindow::initConnectC()
{
    connect(ui->pushButtonC, SIGNAL(clicked()),this,SLOT(onClickButtonC()));
    connect(SignalHub::inst(),SIGNAL(currentSelectIDChanged(int)),this,SLOT(onReactC(int)));
}

void MainWindow::onClickButtonC()
{
    int id = ui->listWidgetC->currentItem()->text().toInt();
    SignalHub::inst()->emitCurrentSelectIDChanged(id);
}

void MainWindow::onReactC(int id)
{
    QList<QListWidgetItem*> list = ui->listWidgetC->findItems(QString::number(id),Qt::MatchExactly);
    ui->listWidgetC->setCurrentRow(-1);//取消选择
    if(!list.isEmpty()){
        ui->listWidgetC->setCurrentItem(list.first());
    }
}


//--组件D--
void MainWindow::initConnectD()
{
    connect(ui->pushButtonD, SIGNAL(clicked()),this,SLOT(onClickButtonD()));
    connect(SignalHub::inst(),SIGNAL(currentSelectIDChanged(int)),this,SLOT(onReactD(int)));
}

void MainWindow::onClickButtonD()
{
    int id = ui->listWidgetD->currentItem()->text().toInt();
    SignalHub::inst()->emitCurrentSelectIDChanged(id);
}

void MainWindow::onReactD(int id)
{
    QList<QListWidgetItem*> list = ui->listWidgetD->findItems(QString::number(id),Qt::MatchExactly);
    ui->listWidgetD->setCurrentRow(-1);//取消选择
    if(!list.isEmpty()){
        ui->listWidgetD->setCurrentItem(list.first());
    }
}

