#include "widget.h"
#include "ui_widget.h"

#include "mydelegate.h"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    string_model = new QStringListModel();
    file_model = new QFileSystemModel();
    stand_model = new QStandardItemModel(3,2,this);


    testStringModel();
}

Widget::~Widget()
{
    delete ui;
}



void Widget::testStringModel()
{
    QStringList list;
    list << "tom" << "jerry"  << "mike" << "jackMa";
    string_model->setStringList(list);

    ui->listView->setModel(string_model);
    ui->treeView->setModel(string_model);
    ui->columnView->setModel(string_model);
    ui->tableView->setModel(string_model);
}


void Widget::testFileModel()
{
    file_model->setRootPath(QDir::currentPath());

    ui->listView->setModel(file_model);
    ui->treeView->setModel(file_model);
    ui->columnView->setModel(file_model);
    ui->tableView->setModel(file_model);

    ui->tableView->setRootIndex(file_model->index(QDir::currentPath()));
}

void Widget::testStandardModel()
{
    stand_model->setHeaderData(0,Qt::Horizontal, QObject::tr("Name"));
    stand_model->setHeaderData(1,Qt::Horizontal, QObject::tr("Age"));


    stand_model->setData(stand_model->index(0,0),"tyw");
    stand_model->setData(stand_model->index(0,1),"26");

    stand_model->setData(stand_model->index(1,0),"jack");
    stand_model->setData(stand_model->index(1,1),"44");


    QStandardItem* root = new QStandardItem(2,1);
    root->setText("baba");
    QStandardItem* ch = new QStandardItem(2,0);
    ch->setText("erzi");
    root->setChild(0,0, ch);
    stand_model->setItem(2,root);

    ui->listView->setModel(stand_model);
    ui->treeView->setModel(stand_model);
    ui->columnView->setModel(stand_model);
    ui->tableView->setModel(stand_model);
}


void Widget::on_pushButton_del_clicked()
{

}

void Widget::on_pushButton_string_clicked()
{
    testStringModel();

//    ui->listView->setItemDelegate(new MyDelegate(ui->listView));//委托： 确保输入不含数字
}

void Widget::on_pushButton_file_clicked()
{
    testFileModel();

    ui->treeView->setEditTriggers(QAbstractItemView::DoubleClicked);

    //ui->listView->setItemDelegate(new MyDelegate(ui->listView));//委托： 确保输入不含数字

}

void Widget::on_pushButton_std_clicked()
{
    testStandardModel();
}
