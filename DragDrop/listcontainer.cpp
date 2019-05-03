#include "listcontainer.h"
#include<QStringList>
#include<QMimeData>
#include<QDrag>
#include<QDragEnterEvent>

#include "../Dialogs/FindDialog/dialog.h"
#include"../Dialogs/GotoDialog/gotocellDialog.h"
#include"../Dialogs/SortDialog/sortdialog.h"

ListContainer::ListContainer(QWidget *parent): QListWidget(parent)
{
    QStringList strList;
    strList<<"findDialog"<<"cellDialog"<<"sortDialog";
    addItems(strList);
    connect(this,SIGNAL(itemDoubleClicked(QListWidgetItem *)),
            this,SLOT(on_itemDoubleClicked(QListWidgetItem *)));

    setDragEnabled(true);
    setDropIndicatorShown(true);
}

ListContainer::~ListContainer()
{

}

void ListContainer:: on_itemDoubleClicked(QListWidgetItem *item)
{
    if(item->text()=="findDialog"){
        FindDialog *dialog=new FindDialog();
        dialog->show();
    }else if(item->text()=="cellDialog"){
        GoToCellDialog *dialog=new GoToCellDialog();
        dialog->show();
    }else if(item->text()=="sortDialog"){
        SortDialog *dialog=new SortDialog();
        dialog->show();
    }
}

void ListContainer::dropExec()
{
    on_itemDoubleClicked(currentItem());
}

void ListContainer::startDrag(Qt::DropActions supportedActions)
{
    QListWidgetItem *item=currentItem();

    //build MimeData
    QByteArray itemData;
    QDataStream dataStream(&itemData,QIODevice::WriteOnly);
    QString text=item->text();
    dataStream<<text;
    QMimeData * mimeData = new QMimeData;
    mimeData->setData("openDialog", itemData);

    //build QDrag
    QDrag *drag=new QDrag(this);
    drag->setMimeData(mimeData);

    //execute QDrag
    drag->exec(Qt::MoveAction);
}

//void ListContainer::mousePressEvent(QMouseEvent *event)
//{
//    //handle the click etc. event
//    QListWidget::mousePressEvent(event);

//    QListWidgetItem *item=currentItem();

//    //build MimeData
//    QByteArray itemData;
//    QDataStream dataStream(&itemData,QIODevice::WriteOnly);
//    QString text=item->text();
//    dataStream<<text;
//    QMimeData * mimeData = new QMimeData;
//    mimeData->setData("openDialog", itemData);

//    //build QDrag
//    QDrag *drag=new QDrag(this);
//    drag->setMimeData(mimeData);

//    //execute QDrag
//    drag->exec(Qt::MoveAction);
//}

//void  ListContainer::dragEnterEvent(QDragEnterEvent *event)
//{
//    if(event->mimeData()->hasFormat("openDialog"))
//    {
//        if(event->source()==this){

//        }else {
//            event->accept();
//        }
//    }
//    else{
//        event->ignore();
//    }
//}


