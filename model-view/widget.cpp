#include "widget.h"
#include "ui_widget.h"
#include "mydelegate.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    initData();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initData()
{
    ///////////////////////////////
    QStringList list;
    list << "tom" << "jerry"  << "mike" << "jackMa";
    m_stringModel = new QStringListModel();
    m_stringModel->setStringList(list);
    ///////////////////////////////
    m_fileModel = new QFileSystemModel();
    m_fileModel->setRootPath(QDir::currentPath());
    ///////////////////////////////
    m_standardModel = new QStandardItemModel(3,2,this);
    m_standardModel->setHeaderData(0,Qt::Horizontal, QObject::tr("Name"));
    m_standardModel->setHeaderData(1,Qt::Horizontal, QObject::tr("Age"));

    m_standardModel->setData(m_standardModel->index(0,0),"tyw");
    m_standardModel->setData(m_standardModel->index(0,1),"26");
    m_standardModel->setData(m_standardModel->index(1,0),"jack");
    m_standardModel->setData(m_standardModel->index(1,1),"44");

    QStandardItem* baba = new QStandardItem(tr("baba"));
    m_standardModel->setItem(2,baba);
    //    m_standardModel->appendRow(baba);

    QStandardItem* ch = new QStandardItem(2,0);
    ch->setText("erzi");
    baba->setChild(0,0, ch);



}

void Widget::on_pushButton_del_clicked()
{
    //    QMessageBox::information(this,"1",m_standardModel->data(m_standardModel->index(0,0)).toString());
    if(m_standardModel->removeRows(1,1)){
        QMessageBox::information(this,"removeRows","ok");
    }

    //    m_standardModel->setData(m_standardModel->index(0,0),QString("new name"));
    //m_standardModel->removeRow(0);
}

void Widget::on_pushButton_string_clicked()
{
    ui->listView->setModel(m_stringModel);
    ui->treeView->setModel(m_stringModel);
    ui->tableView->setModel(m_stringModel);
    ui->columnView->setModel(m_stringModel);

    //    ui->listView->setItemDelegate(new MyDelegate(ui->listView));//委托： 确保输入不含数字

    //视图选择模型
    ui->listView->setSelectionModel(ui->columnView->selectionModel());
}

void Widget::on_pushButton_file_clicked()
{
    ui->listView->setModel(m_fileModel);
    ui->treeView->setModel(m_fileModel);
    ui->columnView->setModel(m_fileModel);
    ui->tableView->setModel(m_fileModel);

    ui->tableView->setRootIndex(m_fileModel->index(QDir::currentPath()));
    ui->treeView->setEditTriggers(QAbstractItemView::DoubleClicked);
    //ui->listView->setItemDelegate(new MyDelegate(ui->listView));//委托： 确保输入不含数字

}

void Widget::on_pushButton_std_clicked()
{
    ui->listView->setModel(m_standardModel);
    ui->treeView->setModel(m_standardModel);
    ui->columnView->setModel(m_standardModel);
    ui->tableView->setModel(m_standardModel);


    //视图选择模型
    ui->listView->setSelectionModel(ui->columnView->selectionModel());
}



