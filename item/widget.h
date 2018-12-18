#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QFileSystemModel>
#include <QStringListModel>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void testStringModel();

    void testFileModel();

    void testStandardModel();

    void on_pushButton_del_clicked();

    void on_pushButton_string_clicked();

    void on_pushButton_file_clicked();

    void on_pushButton_std_clicked();

private:
    Ui::Widget *ui;


    QStringListModel* string_model;
    QStandardItemModel* stand_model;
    QFileSystemModel* file_model;

};

#endif // WIDGET_H
