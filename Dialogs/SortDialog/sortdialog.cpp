#include "sortdialog.h"
#include "ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);
    ui->groupBox_Second->hide();
    ui->groupBox_Third->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    setColumRange('A','Z');
}

SortDialog::~SortDialog()
{
    delete ui;
}

void SortDialog::setColumRange(QChar first,QChar last)
{
    ui->cmb_First->clear();
    ui->cmb_second->clear();
    ui->cmb_third->clear();

    ui->cmb_second->addItem(tr("None"));
    ui->cmb_third->addItem(tr("None"));

    ui->cmb_First->setMinimumSize(ui->cmb_second->sizeHint());

    QChar ch=first;
    while(ch<=last)
    {
        ui->cmb_First->addItem(QString(ch));
        ui->cmb_second->addItem(QString(ch));
        ui->cmb_third->addItem(QString(ch));
        ch=ch.unicode()+1;
    }
}
