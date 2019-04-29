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

    double totalCost = 0;
    double totalMoney = 0;

    ui->plainTextEdit_result->clear();
    for(int i = 0; i < time; ++i){
        ui->plainTextEdit_result->appendPlainText(tr("Stage %1:").arg(i+1));

        totalCost += money; //成本

        totalMoney = totalMoney * (1.0 + rate) + money;

        ui->plainTextEdit_result->appendPlainText(tr("totalCost: %1, totalMoney: %2").arg(totalCost).arg(totalMoney));
    }

    ui->lineEdit_totalCost->setText(QString::number(totalCost, 'f', 2));
    ui->lineEdit_totalMoney->setText(QString::number(totalMoney, 'f', 2));
    ui->lineEdit_totalInterest->setText(QString::number(totalMoney - totalCost, 'f', 2));
}
