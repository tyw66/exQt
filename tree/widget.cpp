#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mainLayout = new QGridLayout(this);
    m_treeWidget = new MyTreeWidget(this);
    m_treeWidget_copy = new MyTreeWidget(this);

    mainLayout->addWidget(m_treeWidget,0,0);
    mainLayout->addWidget(m_treeWidget_copy,0,1);


}

Widget::~Widget()
{
    delete ui;
}
