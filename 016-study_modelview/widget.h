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
    void on_pushButton_string_clicked();

    void on_pushButton_file_clicked();

    void on_pushButton_std_clicked();

    void on_pushButton_del_clicked();


private:
    void initData();

private:
    Ui::Widget *ui;


    QStringListModel* m_stringModel;
    QStandardItemModel* m_standardModel;
    QFileSystemModel* m_fileModel;

};

#endif // WIDGET_H
