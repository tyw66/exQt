#ifndef MYTREE_H
#define MYTREE_H

#include<QTreeWidget>

class MyTree : public QTreeWidget
{
public:
    MyTree();

protected:
    /**
     * @brief 右键菜单
     */
    virtual void contextMenuEvent(QContextMenuEvent * event);

private slots:
    void slotTest();

};

#endif // MYTREE_H
