#include "toydialog.h"
#include "ui_toydialog.h"
#include <QMessageBox>
#include <QPushButton>

ToyDialog::ToyDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ToyDialog)
{
    ui->setupUi(this);

    QPushButton *popButton = new QPushButton(tr("This is a  pop button."), this);


    menu = new QMenu(tr("Library"),popButton);
    menu->addAction("Library001");
    menu->addAction("Library002");
    menu->addAction("Library003");

    menu_001 = new QMenu(tr("Library001"),menu);
    menu_001->addAction("item001",this,SLOT(slotHello()));
    menu_001->addAction("item002");
    menu->addMenu(menu_001);

    popButton->setMenu(menu);

    popButton->setStatusTip("balabala....");


    setCentralWidget(popButton);
}

ToyDialog::~ToyDialog()
{
    delete ui;
}

void ToyDialog::slotHello()
{
    QMessageBox::information(this,"hello","hello");
}
