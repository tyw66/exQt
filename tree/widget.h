#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGridLayout>

#include "mytreewidget.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    MyTreeWidget* m_treeWidget;
    MyTreeWidget* m_treeWidget_copy;
    QGridLayout* mainLayout;

};

#endif // WIDGET_H
