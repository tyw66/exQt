#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include<QObject>
#include <QTreeWidget>

class MyTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    MyTreeWidget(QWidget* parent = 0);

protected:
    /**
     * @brief 右键菜单
     */
    virtual void contextMenuEvent(QContextMenuEvent * event);
    /**
     * @brief dragEnterEvent
     * @param event
     */
    virtual void dragEnterEvent(QDragEnterEvent *event);
    /**
     * @brief dragMoveEvent
     * @param event
     */
    virtual void dragMoveEvent(QDragMoveEvent *event);
    /**
     * @brief dropEvent
     * @param event
     */
    virtual void dropEvent(QDropEvent *event);
    /**
     * @brief mousePressEvent
     * @param event
     */
    virtual void mousePressEvent(QMouseEvent* event);


private slots:
    void onClick();

   void onSetCurrent();
};

#endif // MYTREEWIDGET_H
