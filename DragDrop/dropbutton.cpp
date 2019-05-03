#include "dropbutton.h"

#include"listcontainer.h"

DropButton::DropButton(QWidget *parent) : QPushButton(parent)
{
    setText("drag to here, and drop to open.");
    setAcceptDrops(true);
}

DropButton::~DropButton()
{

}

void DropButton::dragEnterEvent(QDragEnterEvent *event)
{
        if(event->mimeData()->hasFormat("openDialog"))
        {
            if(event->source()==this){

            }else {
                event->accept();
            }
        }
        else{
            event->ignore();
        }
}

void DropButton::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasFormat("openDialog"))
    {
        ListContainer *listcontainer=qobject_cast<ListContainer*>(event->source());
        if(listcontainer)
            listcontainer->dropExec();
        event->accept();
    }
    else{
        event->ignore();
    }
}

