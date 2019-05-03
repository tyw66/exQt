#ifndef LISTCONTAINER_H
#define LISTCONTAINER_H

//#include <QWidget>
#include<QListWidget>

class ListContainer : public QListWidget
{
    Q_OBJECT
public:
    explicit ListContainer(QWidget *parent = 0);
    ~ListContainer();


public:
 void dropExec();
private:
 void  startDrag(Qt::DropActions supportedActions) ;
 //void mousePressEvent(QMouseEvent *event);
//void dragEnterEvent(QDragEnterEvent *event);


signals:

private slots:
 void on_itemDoubleClicked(QListWidgetItem*);



};

#endif // LISTCONTAINER_H
