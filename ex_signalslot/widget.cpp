#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(&m_foo, SIGNAL(sigShowMessage()),
            this, SLOT(onShowMessage()));

//    connect(ui->pushButton, SIGNAL(clicked()),
//            &m_foo, SIGNAL(sigShowMessage()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::onShowMessage()
{
//    QMessageBox::information(this, "message", "hello");
    qDebug() << "onShowMessage";
}


void Widget::on_pushButton_clicked()
{
    //
    qDebug() << "on_pushButton_clicked()";
    m_foo.emitSig();

    //
    qDebug() << "after";
}
