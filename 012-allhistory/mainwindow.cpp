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
    QString dyChina;
    for(Dynasty& dy : m_dataChina) {
        if(!(year < dy.begin || year > dy.end)){
            dyChina.append(dy.name);
            dyChina.append(" ");
        }
    }
    //日本
    QString dyJapan;
    for(Dynasty& dy : m_dataJapan) {
        if(!(year < dy.begin || year > dy.end)){
            dyJapan.append(dy.name);
            dyJapan.append(" ");
        }
    }

    //
    ui->label_china->setText(dyChina);
    ui->label_japan->setText(dyJapan);
}

