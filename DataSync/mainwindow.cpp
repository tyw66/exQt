#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "signalhub.h"

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
    connect(SignalHub::inst(),SIGNAL(state1Changed(QString)),this,SLOT(onReactA(QString)));
}

void MainWindow::onClickButtonA()
{
    qDebug() << __FUNCTION__;
    QString id = ui->textEditA->toPlainText();
    SignalHub::inst()->emitState1Changed(id);//Qt4
    //    emit Common::inst()->state1Changed(id);//Qt5

}

void MainWindow::onReactA(const QString &msg)
{
    qDebug() << __FUNCTION__;
    ui->textEditA->clear();
    ui->textEditA->setPlainText(msg);
}

//--组件B--
void MainWindow::initConnectB()
{
    connect(ui->pushButtonB, SIGNAL(clicked()),this,SLOT(onClickButtonB()));
    connect(SignalHub::inst(),SIGNAL(state1Changed(QString)),this,SLOT(onReactB(QString)));
}

void MainWindow::onClickButtonB()
{
    qDebug() << __FUNCTION__;
    QString id = "-1";
    if(ui->listWidgetB->currentItem()){
        id = ui->listWidgetB->currentItem()->text();
    }
    SignalHub::inst()->emitState1Changed(id);
}

void MainWindow::onReactB(const QString& msg)
{
    qDebug() << __FUNCTION__;
    bool blocked = ui->listWidgetB->blockSignals(true);

    QList<QListWidgetItem*> list = ui->listWidgetB->findItems(msg,Qt::MatchExactly);
    ui->listWidgetB->setCurrentRow(-1);//取消选择
    if(!list.isEmpty()){
        ui->listWidgetB->setCurrentItem(list.first());

    }
    ui->listWidgetB->blockSignals(blocked);
}

//--组件C--
void MainWindow::initConnectC()
{
    connect(ui->listWidgetC, SIGNAL(currentTextChanged(QString)),this,SLOT(onChangeListWidget()));
    connect(SignalHub::inst(),SIGNAL(state1Changed(QString)),this,SLOT(onReactC(QString)));
}

void MainWindow::onChangeListWidget()
{
    qDebug() << __FUNCTION__;
    QString id = "-1";
    if(ui->listWidgetC->currentItem()){
        id = ui->listWidgetC->currentItem()->text();
    }
    SignalHub::inst()->emitState1Changed(id);
}

void MainWindow::onReactC(const QString &msg)
{
    qDebug() << __FUNCTION__;
    bool blocked = ui->listWidgetC->blockSignals(true);

    QList<QListWidgetItem*> list = ui->listWidgetC->findItems(msg,Qt::MatchExactly);
    ui->listWidgetC->setCurrentRow(-1);//取消选择
    if(!list.isEmpty()){
        ui->listWidgetC->setCurrentItem(list.first());
    }

    ui->listWidgetC->blockSignals(blocked);
}



//--组件D--
void MainWindow::initConnectD()
{
    //发
    connect(ui->spinBox,SIGNAL(textChanged(QString)),this,SLOT(onChangeSpinBox(QString)));
    //收
    connect(SignalHub::inst(),SIGNAL(state1Changed(QString)),this,SLOT(onReactD(QString)));
}

void MainWindow::onChangeSpinBox(const QString &value)
{
    qDebug() << __FUNCTION__;
    SignalHub::inst()->emitState1Changed(value);
}

void MainWindow::onReactD(const QString &msg)
{
    qDebug() << __FUNCTION__;
    bool blocked = ui->spinBox->blockSignals(true);

    bool ok;
    int value = msg.toInt(&ok, 10);
    if(ok && ok==true){
        ui->spinBox->setValue(value);
    }else{
        ui->spinBox->clear();
    }

    ui->spinBox->blockSignals(blocked);
}

