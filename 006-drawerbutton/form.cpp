#include "form.h"
#include "ui_form.h"
#include "./drawerwidget.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    DrawerWidget* widget1 = new DrawerWidget();
    DrawerWidget* widget2 = new DrawerWidget();
    DrawerWidget* widget3 = new DrawerWidget();

    QWidget* mainWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(widget1);
    layout->addWidget(widget2);
    layout->addWidget(widget3);
    mainWidget->setLayout(layout);

    ui->scrollArea->setWidget(mainWidget);
//    ui->scrollArea->setWidgetResizable(true);
}

Form::~Form()
{
    delete ui;
}
