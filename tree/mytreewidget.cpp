#include "mytreewidget.h"

#include <QTreeWidgetItem>
#include <QDragEnterEvent>
#include <QDebug>

MyTreeWidget::MyTreeWidget(QWidget *parent) : QTreeWidget(parent)
{
    setHeaderHidden(true);//隐藏表头

    //    setMouseTracking(true);
    setDragEnabled(true);
    setAcceptDrops(true);
    setDragDropMode(QAbstractItemView::InternalMove);

    //    connect(this,SIGNAL(activated(QModelIndex)), this, SLOT(onClick()));
    //    connect(this,SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(onSetCurrent()));
    //    connect(this,SIGNAL(currentItemChanged(QTreeWidgetItem*,QTreeWidgetItem*)),this, SLOT(onSetCurrent()));


    for(int i = 0; i < 3; ++i){
        QString name = tr("group_%1").arg(i);
        QTreeWidgetItem* item = new QTreeWidgetItem(this);
        item->setText(0, name);
        for(int j = 0; j < i; ++j){
            QString name = tr("item_%1").arg(j);
            QTreeWidgetItem* subitem = new QTreeWidgetItem(item);
            subitem->setText(0, name);
            setCurrentItem(subitem);
        }

    }

}

void MyTreeWidget::contextMenuEvent(QContextMenuEvent *event)
{
    for(int i = 0; i < 3; ++i){
        QString name = tr("group_%1").arg(i);
        QTreeWidgetItem* item = new QTreeWidgetItem(this);
        item->setText(0, name);
        for(int j = 0; j < i; ++j){
            QString name = tr("item_%1").arg(j);
            QTreeWidgetItem* subitem = new QTreeWidgetItem(item);
            subitem->setText(0, name);
            setCurrentItem(subitem);
        }

    }


}



void MyTreeWidget::dragEnterEvent(QDragEnterEvent *event)
{
    //    event->accept();
    //    event->ignore();
    //    QTreeWidget::dragEnterEvent(event);
}

void MyTreeWidget::dragMoveEvent(QDragMoveEvent *event)
{

}

void MyTreeWidget::dropEvent(QDropEvent *event)
{

}

void MyTreeWidget::mousePressEvent(QMouseEvent *event)
{
    //accept和ignore都会使Press失效 不发信号
    //        event->accept();
    //        event->ignore();
    QTreeWidget::mousePressEvent(event);
}

void MyTreeWidget::onClick()
{
    qDebug()<<"onClick()";
}

void MyTreeWidget::onSetCurrent()
{
    qDebug()<<"onSetCurrent())";
}
