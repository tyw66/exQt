#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->slider_time,SIGNAL(valueChanged(int)),
            this,SLOT(onTimeChanged(int)));

    readData(":/data/China",m_dataChina);
    readData(":/data/Japan",m_dataJapan);
    readData(":/data/Yilang",m_dataYilang);
    readData(":/data/Yidali",m_dataYidali);
    readData(":/data/Yinguo",m_datayinguo);
    readData(":/data/Xila",m_dataXila);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readData(const QString &filePath, QVector<Dynasty> &data)
{
    QFile file(filePath);
    if(file.open(QFile::ReadOnly)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            QStringList info = line.split(' ', QString::SkipEmptyParts);
            if(info.size() == 3){
                Dynasty dy;
                dy.name = info[0];
                dy.begin = info[1].toInt();
                dy.end = info[2].toInt();
                data.push_back(dy);
                qDebug() << dy.name << " " << dy.begin << " "<< dy.end;
            }
        }
        file.close();
    }
}



void MainWindow::onTimeChanged(int year)
{
    ui->label_year->setText(QString::number(year));

    //中国
    QString dyChina = makeInfo(year, m_dataChina);
    ui->label_china->setText(dyChina);

    //日本
    QString dyJapan = makeInfo(year, m_dataJapan);
    ui->label_japan->setText(dyJapan);

    //伊朗
    QString dyYilang = makeInfo(year, m_dataYilang);
    ui->label_yilang->setText(dyYilang);

    //意大利
    QString dyYidali = makeInfo(year, m_dataYidali);
    ui->label_italy->setText(dyYidali);

    //英国
    QString dyYinguo = makeInfo(year, m_datayinguo);
    ui->label_england->setText(dyYinguo);

    //希腊
    QString dyXila = makeInfo(year, m_dataXila);;
    ui->label_greece->setText(dyXila);
}

QString MainWindow::makeInfo(int year, const QVector<Dynasty> &vec)
{
    QString info;
    for(const Dynasty& dy : vec) {
        if(!(year < dy.begin || year > dy.end)){
            info.append(dy.name);
            info.append(" ");
        }
    }
    return info;
}

