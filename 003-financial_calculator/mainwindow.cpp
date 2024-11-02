#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //限制为数字数入
    ui->lineEdit_money->setValidator(new QIntValidator(0, 9999999));
    ui->lineEdit_time->setValidator(new QIntValidator(0,999));
    ui->lineEdit_rate->setValidator(new QRegExpValidator(QRegExp("^[0]{1}([.]([0-9]){4})?$")));

    //信号槽
    connect(ui->pushButton_cal, SIGNAL(clicked()), this, SLOT(onCalculate()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readInput()
{
    m_money = ui->lineEdit_money->text().toDouble();
    m_time = ui->lineEdit_time->text().toInt();
    m_rate = ui->lineEdit_rate->text().toDouble();
    m_singleFlag = ui->checkBox_singleMoney->isChecked();
}



void MainWindow::onCalculate()
{
    readInput();

    double totalCost = 0;           //累计投入
    double totalMoney = 0;          //累计金额
    double interest = 0;                //利息
    ui->plainTextEdit_result->clear();

    //各期
    for(int i = 0; i < m_time; ++i){
        ui->plainTextEdit_result->appendPlainText(tr("Stage %1 start:").arg(i+1));
        //算当期利息
        interest = totalMoney * m_rate;
        totalMoney += interest;
        ui->plainTextEdit_result->appendPlainText(tr("current interest: %1").arg(interest));

        if(!m_singleFlag){
            //如果是多笔投的情况
            totalCost += m_money;
            totalMoney += m_money;
            ui->plainTextEdit_result->appendPlainText(tr("add invest money: %1").arg(m_money));
        }else if(i == 0){
            //如果是单笔投的情况，只算第一期的本金
            totalCost += m_money;
            totalMoney += m_money;
            ui->plainTextEdit_result->appendPlainText(tr("add invest money: %1").arg(m_money));
        }

        ui->plainTextEdit_result->appendPlainText(tr("totalCost: %1, totalMoney: %2%3").arg(totalCost).arg(totalMoney).arg("\n"));
    }


    //下一期，为了算最后一期的利息
    ui->plainTextEdit_result->appendPlainText(tr("Last stage:"));
    interest = totalMoney * m_rate;
    totalMoney += interest;
    ui->plainTextEdit_result->appendPlainText(tr("current interest: %1").arg(interest));
    ui->plainTextEdit_result->appendPlainText(tr("totalCost: %1, totalMoney: %2%3").arg(totalCost).arg(totalMoney).arg("\n"));


    //结果区
    ui->lineEdit_totalCost->setText(QString::number(totalCost, 'f', 2));
    ui->lineEdit_totalMoney->setText(QString::number(totalMoney, 'f', 2));
    ui->lineEdit_totalInterest->setText(QString::number(totalMoney - totalCost, 'f', 2));

    drawChart();

}

void MainWindow::onShowStatusInfo(double value)
{
    ui->statusBar->setStatusTip(QString::number(value));
}


void MainWindow::drawChart()
{
    m_scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setBackgroundBrush(QColor(255,255,255,255));

    ////////////////////////////////////////////////
    double totalCost = 0;           //累计投入
    double totalMoney = 0;          //累计金额
    double interest = 0;                //利息

    double xPos = 0, yPos = 0;
//    double value = 0;
    //    QGraphicsRectItem* item;


    foreach (QGraphicsRectItem* item, m_items) {
        delete item;
    }
    m_items.clear();


    //各期
    for(int i = 0; i < m_time; ++i){
        xPos = 0;
        yPos = i * (m_HEIGHT+5);

        //add old
        QGraphicsRectItem* item = new QGraphicsRectItem();
        item->setRect(xPos,yPos,totalMoney,m_HEIGHT);
        item->setBrush(QBrush(QColor(238,232,213)));
        item->setToolTip(QString::number(totalMoney));
        m_items.push_back(item);
        m_scene->addItem(item);

        xPos += totalMoney;//

        //算当期利息
        interest = totalMoney * m_rate;
        totalMoney += interest;


        if(!m_singleFlag){
            //如果是多笔投的情况
            totalCost += m_money;
            totalMoney += m_money;


        }else if(i == 0){
            //如果是单笔投的情况，只算第一期的本金
            totalCost += m_money;
            totalMoney += m_money;
        }

//        value = totalMoney;

        //add interset

        item = new QGraphicsRectItem();
        item->setRect(xPos,yPos,interest,m_HEIGHT);
        item->setToolTip(QString::number(interest));
        item->setBrush(QBrush(QColor(23,168,26)));
        m_items.push_back(item);
        m_scene->addItem(item);

        //add cost
        xPos += interest;
        item = new QGraphicsRectItem();
        item->setRect(xPos,yPos,m_money,m_HEIGHT);
        item->setToolTip(QString::number(m_money));
        item->setBrush(QBrush(QColor(253,246,227)));
        m_items.push_back(item);
        m_scene->addItem(item);

    }


    //缩放图形 铺满控件
    double fx = ui->graphicsView->width() / (totalMoney * 1.01) * 1.5;
    double fy = ui->graphicsView->height() / yPos * 1.1;
    ui->graphicsView->scale(fx, fy);


}
