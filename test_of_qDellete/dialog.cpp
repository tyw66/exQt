#include "dialog.h"
#include "ui_dialog.h"
#include <QListWidgetItem>
#include<iostream>
#include<QList>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onButtonClick()));
        connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onButton2Click()));

    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(onButtonClick_delte()));

}

Dialog::~Dialog()
{
    delete ui;
}


class Person{
public:
    Person();
    Person(int id_,QString name_)
    {
        id=id;
        name=name_;
    }

    ~Person(){}

private:
    int id;
    QString name;
};


void Dialog::onButtonClick(){

    test(100000);
//    //[re.]可以把这段错误代码留下来研究以后看内存地址
//    QListWidgetItem item;
//    for(int i=0;i<10;i++){

//        item.setText("eat memory ~~");
//        ui->listWidget->addItem(&item);
//        std::cout<<&item<<std::endl;
//    }
//ui->listWidget->addItem(&item);


//    ui->listWidget->clear();
//    for(int i=0;i<100000;i++){
//        QListWidgetItem* item=new QListWidgetItem(ui->listWidget);
//        item->setText(QString::number(i));
//        ui->listWidget->addItem(item);
//}
//===================================================
    //当T的类型为指针时，调用clear()方法并不能释放其内存!
    //qDeleteAll(list.begin(),list.end());//<-要加这句话
//    list.clear();
//    for(int i=0;i<500000;i++){
//        list.append(new Person(i,"eat memory ~~"));
//        std::cout<<i<<"eat memory ~~"<<std::endl;

//    }

//===================================================
//for(int i=0;i<100000;i++){
//    p=new Person(i,"eat memory ~~");
//    std::cout<<i<<std::endl;
////    delete p; //如果不delete就会内存泄漏
////    p=nullptr;
//}
//===================================================



}

void Dialog::onButton2Click()
{
//        ui->listView->clear();
//        for(int i=0;i<1000;i++){
//            QListWidgetItem* item=new QListWidgetItem(ui->listWidget);
//            item->setText(QString::number(i));
//            ui->listView->addItem(item);
//        }
}

void Dialog::onButtonClick_delte()
{
    qDeleteAll(list.begin(),list.end());
}

void Dialog::test(int number)
{
    ui->listWidget->clear();
    for(int i=0;i<number;i++){
        QListWidgetItem* item=new QListWidgetItem(ui->listWidget);
        item->setText(QString::number(i));
        ui->listWidget->addItem(item);
}
}
