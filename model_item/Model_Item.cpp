#include "Model_Item.h"
#include "ui_Model_Item.h"

#include<QSplitter>
#include<QFileSystemModel>
#include<QTreeView>
#include<QListView>
#include<QVBoxLayout>
#include <QImage>
#include<QPainter>
#include<QGraphicsView>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(600,300);
    QSplitter *splitter = new QSplitter(this);

    QFileSystemModel* model =new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    QTreeView *tree = new QTreeView(splitter);
    tree->setModel(model);
//    tree->setRootIndex(model->index(QDir::currentPath()));

    QListView *list = new QListView(splitter);
    list->setModel(model);
    list->setRootIndex(model->index(QDir::currentPath()));

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(splitter);
    setLayout(layout);

    qDebug(QString::number(qBound(0,9,10)).toStdString().c_str());
    qCritical("this is a critical");
//    qFatal("this is a fatal");//cause program stop

    qDebug(QString::number(qRound64(2.5)).toStdString().c_str());



}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QImage image(10,10,QImage::Format_RGB32);
    QRgb rgb;
    for(int j=0;j<10;++j){
        for(int i=0;i<10;++i){
            rgb = qRgb(rand()*255,rand()*255,rand()*255);
            image.setPixel(i,j,rgb);
        }
    }

    QPainter p;
    p.begin(this);
    p.setPen(Qt::black);
    p.drawImage(QRect(0,0,300,300),image);
    p.end();

}
