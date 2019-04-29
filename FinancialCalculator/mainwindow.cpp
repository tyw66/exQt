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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_cal_clicked()
{
    double money = ui->lineEdit_money->text().toDouble();
    int time = ui->lineEdit_time->text().toDouble();
    double rate = ui->lineEdit_rate->text().toDouble();
    bool singleFlag = ui->checkBox_singleMoney->isChecked();

    //
    double totalCost = money;
    double totalMoney = money;
    ui->plainTextEdit_result->clear();

    //初始阶段
    ui->plainTextEdit_result->appendPlainText(tr("Stage 1 start:"));
    ui->plainTextEdit_result->appendPlainText(tr("totalCost: %1, totalMoney: %2").arg(money).arg(money));

    //各阶段
    for(int i = 0; i < time; ++i){
        ui->plainTextEdit_result->appendPlainText(tr("Stage %1 end:").arg(i+1));

        totalMoney = totalMoney * (1.0 + rate);

        //如果是多期投的情况 &&
        if(!singleFlag && i >0){
            totalCost += money;
            totalMoney += money;
        }

        ui->plainTextEdit_result->appendPlainText(tr("totalCost: %1, totalMoney: %2").arg(totalCost).arg(totalMoney));
    }

    ui->lineEdit_totalCost->setText(QString::number(totalCost, 'f', 2));
    ui->lineEdit_totalMoney->setText(QString::number(totalMoney, 'f', 2));
    ui->lineEdit_totalInterest->setText(QString::number(totalMoney - totalCost, 'f', 2));
}
