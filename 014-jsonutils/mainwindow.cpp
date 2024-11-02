#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "./jsonutils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::string schemaText = ui->textEdit_schema->toPlainText().toStdString();
    std::string dataText = ui->textEdit_data->toPlainText().toStdString();

    std::string out;
    JsonUtils::schema(schemaText,dataText,out);

    ui->textEdit_output->setText(QString::fromStdString(out));
}

