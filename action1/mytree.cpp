#include "mytree.h"
#include<iostream>
#include<QMenu>
#include<QTreeWidgetItem>
#include<QContextMenuEvent>

MyTree::MyTree()
{

}

void MyTree::contextMenuEvent(QContextMenuEvent *event)
{
    QTreeWidgetItem *curItem = itemAt(event->pos());

    QMenu menu;
    if (!curItem){//空白地方右键
        QAction* action_new = new QAction(tr("test"),this);
//        connect(action_new,SIGNAL(triggered()),this,SLOT(slotTest()));
//        menu.addAction(action_new);

        menu.addAction(tr("test"),this,SLOT(slotTest()));
    }


    menu.exec(event->globalPos());
}

void MyTree::slotTest()
{
    std::cout<<"123"<<std::endl;
}
