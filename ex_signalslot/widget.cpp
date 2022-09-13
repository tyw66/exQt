#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
//    connect(ui->pushButton_1, SIGNAL(clicked()),
//            this, SLOT(onClick1()));
    connect(ui->pushButton_2, SIGNAL(clicked()),
            this, SLOT(onClick2()));

    connect(ui->pushButton_1, "2clicked()",
            this, "1onClick1()");


//    connect(&m_foo, SIGNAL(sigShowMessage()),
//            this, SLOT(onShowMessage()));


}

Widget::~Widget()
{
    delete ui;
}

//void Widget::onShowMessage()
//{
////    QMessageBox::information(this, "message", "hello");
//    qDebug() << "onShowMessage";
//}


void Widget::onClick1()
{
    qDebug() << __FUNCTION__;
//    m_foo.emitSig();

    //
//    qDebug() << "after";
}

void Widget::onClick2()
{
    qDebug() << __FUNCTION__;
}

int Widget::getGrade() const
{
    return m_grade;
}

void Widget::setGrade(int value)
{
    m_grade = value;
}
