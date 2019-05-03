#include "mainboard.h"
#include "ui_mainboard.h"
#include"dialog.h"
#include"gotocellDialog.h"
#include"sortdialog.h"

MainBoard::MainBoard(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MainBoard)
{
  ui->setupUi(this);
}

MainBoard::~MainBoard()
{
  delete ui;
}

void MainBoard::on_pushButton_clicked()
{
  FindDialog *dlg=new FindDialog();
  dlg->show();
}

void MainBoard::on_pushButton_2_clicked()
{
  GoToCellDialog *dlg=new GoToCellDialog();
  dlg->show();
}

void MainBoard::on_pushButton_3_clicked()
{
  SortDialog *dlg=new SortDialog();
  dlg->show();
}
