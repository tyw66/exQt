#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class Person;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

public slots:
    void onButtonClick();
    void onButton2Click();
    void onButtonClick_delte();

private:
    Ui::Dialog *ui;
    QList<Person*> list;
    Person *p;


    void test(int number);

};

#endif // DIALOG_H
