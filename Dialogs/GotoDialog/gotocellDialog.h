#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include<QDialog>
#include"../Dialogs/ui_gotocellDialog.h"

class GoToCellDialog:public QDialog,public Ui::GoToCellDialog
{
	Q_OBJECT
	
public:
	GoToCellDialog(QWidget *parent=0);
	
private slots:
	void on_lineEdit_textChanged();
	
};
#endif
