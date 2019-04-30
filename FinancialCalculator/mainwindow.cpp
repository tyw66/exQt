#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::drawChart()
{



}
