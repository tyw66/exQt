#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setCentralWidget(ui->plainTextEdit);
    ui->toolBar_1->addAction(ui->action_New);
    ui->toolBar_1->addAction(ui->action_Open);
    ui->toolBar_1->addAction(ui->action_Save);
    ui->toolBar_2->addAction(ui->action_Cut);
    ui->toolBar_2->addAction(ui->action_Copy);
    ui->toolBar_2->addAction(ui->action_Parse);

    connect(ui->action_Close,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->action_Exit,SIGNAL(triggered()),qApp,SLOT(quit()));
    connect(ui->actionAbout_Qt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));

    connect(ui->action_New,SIGNAL(triggered()),this,SLOT(newFile()));
    connect(ui->action_Open,SIGNAL(triggered()),this,SLOT(openFile()));
    connect(ui->action_Save,SIGNAL(triggered()),this,SLOT(saveFile()));
    connect(ui->action_Save_as,SIGNAL(triggered()),this,SLOT(saveFileAs()));
    connect(ui->actionSelect_All,SIGNAL(triggered()),this,SLOT(selectAll()));
    connect(ui->plainTextEdit,SIGNAL(textChanged()),this,SLOT(WindowModified()));

    currentFile="";
    setWindowTitle(tr("new file[*] - EasyNotepad"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::WindowModified()
{
    setWindowModified(ui->plainTextEdit->document()->isModified());
}

void MainWindow::newFile()
{
    if(this->isWindowModified())
    {
        if(QMessageBox::No==QMessageBox::information(this,tr("Hey"),
                                                     tr("This window has not been saved, would you give up it?"),
                                                     QMessageBox::Yes|QMessageBox::No))
        {
            return;
        }
    }
    ui->plainTextEdit->clear();
    setWindowTitle(tr("new file[*] - EasyNotepad"));
    currentFile="";


}

void MainWindow::openFile()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("Open file"),"*","*");
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this,tr("Error"),tr("Can't open the file"));
            return;
        }
        QTextStream in(&file);
        ui->plainTextEdit->setPlainText(in.readAll());
        file.close();

        //
        currentFile=fileName;
        setWindowTitle(QFileInfo(currentFile).fileName()+tr("[*] - EasyNotepad"));
        setWindowModified(false);
        //
    }
}


void MainWindow::saveFile()
{
    if(currentFile.isEmpty())
    {
        saveFileAs();
    }
    else
    {
        save(currentFile);
    }
}
void MainWindow::saveFileAs()
{
    QString fileName=QFileDialog::getSaveFileName(this,tr("Save file"),"new file","*");
    if(fileName.isEmpty())
    {
        return;
    }
    save(fileName);
}
void MainWindow:: save(QString fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,tr("Error"),tr("Can't save the file"));
    }
    else
    {
        QTextStream stream(&file);
        stream<<ui->plainTextEdit->toPlainText();
        stream.flush();
        file.close();
        ui->statusBar->showMessage(tr("File saved."));

        //
        currentFile=fileName;
        setWindowTitle(QFileInfo(currentFile).fileName()+tr("[*] - EasyNotepad"));
        setWindowModified(false);
        //
    }
}









void MainWindow::selectAll()
{
    ui->plainTextEdit->selectAll();
}
