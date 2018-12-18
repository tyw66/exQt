#include "toydialog.h"
#include "ui_toydialog.h"
#include <QMessageBox>

ToyDialog::ToyDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ToyDialog)
{
    ui->setupUi(this);

    menu = new QMenu(tr("Library"),ui->pushButton_001);
    menu->addAction("Library001");
    menu->addAction("Library002");
    menu->addAction("Library003");

    menu_001 = new QMenu(tr("Library001"),menu);
    menu_001->addAction("item001",this,SLOT(slotHello()));
    menu_001->addAction("item002");
    menu->addMenu(menu_001);

    ui->pushButton_001->setMenu(menu);

    ui->pushButton_a->setStatusTip("balabala....");



}

ToyDialog::~ToyDialog()
{
    delete ui;
}

void ToyDialog::slotHello()
{
    QMessageBox::information(this,"hello","hello");
}
