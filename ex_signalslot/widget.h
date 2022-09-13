#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//#include  "foo.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    Q_ENUMS(Week);
    Q_PROPERTY(int m_grade READ getGrade WRITE setGrade)

public:

    enum Week{Monday, Friday, Sunday};



    explicit Widget(QWidget *parent = 0);
    ~Widget();

//public slots:
//    void onShowMessage();


    int getGrade() const;
    void setGrade(int value);

private slots:
    void onClick1();
    void onClick2();

private:
    Ui::Widget *ui;
//    Foo m_foo;

    int m_grade;

};

#endif // WIDGET_H
