#include "window.h"
#include "ui_window.h"



Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    ListContainer *listcontainer = new ListContainer;
    DropButton *dropbutton=new DropButton;
    ui->mainLayout->addWidget(listcontainer);
    ui->mainLayout->addWidget(dropbutton);



}

Window::~Window()
{
    delete ui;
}


