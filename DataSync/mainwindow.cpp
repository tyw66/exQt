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
    connect(SignalHub::inst(),SIGNAL(currentSelectIDChanged(QString)),this,SLOT(onReactA(QString)));
}

void MainWindow::onClickButtonA()
{
    QString id = ui->textEditA->toPlainText();
    SignalHub::inst()->emitCurrentSelectIDChanged(id);//Qt4
    //    emit Common::inst()->currentSelectIDChanged(id);//Qt5

}

void MainWindow::onReactA(const QString &msg)
{
    ui->textEditA->clear();
    ui->textEditA->setPlainText(msg);
}

//--组件B--
void MainWindow::initConnectB()
{
    connect(ui->pushButtonB, SIGNAL(clicked()),this,SLOT(onClickButtonB()));
    //    connect(ui->listWidgetB, SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(onClickButtonB()));
    connect(SignalHub::inst(),SIGNAL(currentSelectIDChanged(QString)),this,SLOT(onReactB(QString)));
}

void MainWindow::onClickButtonB()
{
    QString id = "-1";
    if(ui->listWidgetB->currentItem()){
        id = ui->listWidgetB->currentItem()->text();
    }
    SignalHub::inst()->emitCurrentSelectIDChanged(id);
}

void MainWindow::onReactB(const QString& msg)
{
    QList<QListWidgetItem*> list = ui->listWidgetB->findItems(msg,Qt::MatchExactly);
    ui->listWidgetB->setCurrentRow(-1);//取消选择
    if(!list.isEmpty()){
        ui->listWidgetB->setCurrentItem(list.first());
    }
}

//--组件C--
void MainWindow::initConnectC()
{
    connect(ui->pushButtonC, SIGNAL(clicked()),this,SLOT(onClickButtonC()));
    connect(SignalHub::inst(),SIGNAL(currentSelectIDChanged(QString)),this,SLOT(onReactC(QString)));
}

void MainWindow::onClickButtonC()
{
    QString id = "-1";
    if(ui->listWidgetC->currentItem()){
        id = ui->listWidgetC->currentItem()->text();
    }
    SignalHub::inst()->emitCurrentSelectIDChanged(id);
}

void MainWindow::onReactC(const QString &msg)
{
    QList<QListWidgetItem*> list = ui->listWidgetC->findItems(msg,Qt::MatchExactly);
    ui->listWidgetC->setCurrentRow(-1);//取消选择
    if(!list.isEmpty()){
        ui->listWidgetC->setCurrentItem(list.first());
    }
}


//--组件D--
void MainWindow::initConnectD()
{
    connect(ui->pushButtonD, SIGNAL(clicked()),this,SLOT(onClickButtonD()));
    connect(SignalHub::inst(),SIGNAL(currentSelectIDChanged(QString)),this,SLOT(onReactD(QString)));
}

void MainWindow::onClickButtonD()
{
    QString id = "-1";
    if(ui->listWidgetD->currentItem()){
        id = ui->listWidgetD->currentItem()->text();
    }
    SignalHub::inst()->emitCurrentSelectIDChanged(id);
}

void MainWindow::onReactD(const QString& msg)
{
    QList<QListWidgetItem*> list = ui->listWidgetD->findItems(msg,Qt::MatchExactly);
    ui->listWidgetD->setCurrentRow(-1);//取消选择
    if(!list.isEmpty()){
        ui->listWidgetD->setCurrentItem(list.first());
    }
}

