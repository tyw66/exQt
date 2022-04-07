#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include  "foo.h"

namespace Ui {
class Widget;
}


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void onShowMessage();


private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    Foo m_foo;

};

#endif // WIDGET_H
