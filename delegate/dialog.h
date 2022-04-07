#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QStyledItemDelegate>
#include <QSpinBox>

/**
 * @brief 数字框输入委托类
 * @date 2020/5/9
 */
class SpinBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    SpinBoxDelegate(QObject *parent = 0) : QStyledItemDelegate(parent){}

    //返回一个组件，该组件会被作为用户编辑数据时使用的编辑器，从模型接受数据，返回用户修改的数据
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //提供组件显示时需要的默认值
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    //返回给模型用户修改过的数据
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    //确保上述组件编辑器时能够完整显示出来
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

};

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};




#endif // DIALOG_H
