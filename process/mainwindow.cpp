#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&m_process,SIGNAL(stateChanged(QProcess::ProcessState)), this, SLOT(on_show_status(QProcess::ProcessState)));
    connect(&m_process,SIGNAL(readyRead()), this, SLOT(on_show_result()));
    connect(&m_process,SIGNAL(error(QProcess::ProcessError)), this, SLOT(on_show_error()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::on_pushButton_notepad_clicked()
{
    m_process.start("notepad.exe");

    if (!m_process.waitForStarted())
        return false;

    m_process.write("Qt rocks!");
    m_process.closeWriteChannel();

    if (!m_process.waitForFinished())
        return false;

    QByteArray result = m_process.readAll();

    return true;
}

void MainWindow::on_show_result()
{
    qDebug()<<"showRes:" << endl << QString(m_process.readAll());
}

void MainWindow::on_show_status(QProcess::ProcessState state)
{
    switch (state) {
    case QProcess::NotRunning:{

        qDebug()<<"not running";
        break;
    }
    case QProcess::Starting:{

        qDebug()<<"Starting";
        break;
    }
    default:
        qDebug()<<"running";
        break;
    }
}

void MainWindow::on_show_error()
{
    qDebug()<<"showError:" << endl << QString(m_process.errorString());
}


