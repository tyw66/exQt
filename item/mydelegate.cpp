#include "mydelegate.h"
#include <QLineEdit>

QWidget *MyDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit* editor = new QLineEdit(parent);
    QRegExp re("[a-zA-z]{1,}");
    editor->setValidator(new QRegExpValidator(re));

    return editor;

}

void MyDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString content = index.model()->data(index, Qt::EditRole).toString();
    QLineEdit* lineEditor = static_cast<QLineEdit*>(editor);
    lineEditor->setText(content);
}

void MyDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit* lineEditor = static_cast<QLineEdit*>(editor);
    QString content = lineEditor->text();

    model->setData(index,content,Qt::EditRole);
}

void MyDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
