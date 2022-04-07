#include "dialog.h"
#include "ui_dialog.h"


QWidget *SpinBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)
    Q_UNUSED(index)
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);
    editor->setStyleSheet("background:white; selection-background-color:#00BB9E; selection-color:#FFFFFF;");
    return editor;
}

void SpinBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

void SpinBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox* spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData(index, value, Qt::EditRole);
}

void SpinBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    editor->setGeometry(option.rect);
}



/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <QStringListModel>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle("Demo_delegate");


    QStringList ss;
    ss <<"0"<<"1"<<"2";

    QStringListModel *model = new QStringListModel(this);
    model->setStringList(ss);

    ui->listView->setModel(model);
    ui->listView->setItemDelegate(new SpinBoxDelegate(ui->listView));


}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
    if(ui->listView->currentIndex().isValid()){
        ui->listView->edit(ui->listView->currentIndex());
    }
}



/// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}
