#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->layout_placehold->addWidget(new MyLabel());

    connect(ui->pushButton_apply,SIGNAL(clicked()),
            this,SLOT(onApplyStyleSheet()));

    connect(ui->button_common,SIGNAL(clicked()),
            this,SLOT(onMkCommon()));
    connect(ui->button_dialog,SIGNAL(clicked()),
            this,SLOT(onMkDialog()));
    connect(ui->button_mainwindow,SIGNAL(clicked()),
            this,SLOT(onMkMainWindow()));
    connect(ui->button_midarea,SIGNAL(clicked()),
            this,SLOT(onMkMdiArea()));
    connect(ui->button_mdisubwindow,SIGNAL(clicked()),
            this,SLOT(onMkMdiSubWindow()));
    connect(ui->button_dockwidget,SIGNAL(clicked()),
            this,SLOT(onMkDockWidget()));
    connect(ui->button_statusbar,SIGNAL(clicked()),
            this,SLOT(onMkStatusBar()));
    connect(ui->button_menubar,SIGNAL(clicked()),
            this,SLOT(onMkMenuBar()));
    connect(ui->button_menu,SIGNAL(clicked()),
            this,SLOT(onMkMenu()));

    QLabel *ll = new QLabel("test");
    ui->button_common->setLayout(new QHBoxLayout());
    ui->button_common->layout()->setMargin(0);
    ui->button_common->layout()->addWidget(ll);
    ui->button_common->setStyleSheet("color: blue;");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onApplyStyleSheet()
{
    QString qssContent = ui->textEdit_qss->toPlainText();
    qssContent.replace("$1",m_color01.name());
    qssContent.replace("$2",m_color02.name());
    qssContent.replace("$3",m_color03.name());
    qssContent.replace("$4",m_color04.name());
    qssContent.replace("$5",m_color05.name());
    qssContent.replace("$6",m_color06.name());
    qssContent.replace("$bak6_1",m_color06_1.name());
    qssContent.replace("$bak6_2",m_color06_2.name());
    qssContent.replace("$7",m_color07.name());
    qssContent.replace("$8",m_color08.name());
    qssContent.replace("$9",m_color09.name());
    qssContent.replace("$10",m_color10.name());
    qssContent.replace("$11",m_color11.name());

    qApp->setStyleSheet(qssContent);
}

void MainWindow::onMkCommon()
{
    QString qss = QString(
                "/*---------QWidget----------*/\n"
                "QWidget{\n"
                "    margin:0px;\n"
                "    padding:0px;\n"
                "    font: \"Times New Roman\" 18px normal normal;\n"
                "}\n"
                "QWidget{\n"
                "    color:$1;\n"
                "    background-color:$2;\n"
                "}\n");
    ui->textEdit_qss->append(qss);
}

void MainWindow::onMkMainWindow()
{
    QString qss = QString(
                "/*---------QMainWindow----------*/\n"
                "QMainWindow::separator{\n"
                "    width: 4px;  /* when vertical */\n"
                "    height: 4px; /* when horizontal */\n"
                "}\n"
                "QMainWindow::separator{\n"
                "    background-color:$5;\n"
                "}\n"
                "QMainWindow::separator:hover{\n"
                "    background-color:$6;\n"
                "}\n");

    ui->textEdit_qss->append(qss);
}

void MainWindow::onMkDialog()
{
    QString qss = QString(
                "/*---------QDialog----------*/\n"
                "");

    ui->textEdit_qss->append(qss);
}

void MainWindow::onMkMdiArea()
{
    QString qss = QString(
                "/*---------QMdiArea----------*/\n"
                "");

    ui->textEdit_qss->append(qss);
}

void MainWindow::onMkMdiSubWindow()
{
    QString qss = QString(
                "/*---------QMdiSubWindow----------*/\n"
                "");

    ui->textEdit_qss->append(qss);
}

void MainWindow::onMkDockWidget()
{
    QString qss = QString(
                "/*---------QDockWidget----------*/\n"
                "");

    ui->textEdit_qss->append(qss);
}

void MainWindow::onMkStatusBar()
{
    QString qss = QString(
                "/*---------QStatusBar----------*/\n"
                "QStatusBar{\n"
                "   border-top:2px solid $4;\n"
                "   background:$4;\n"
                "}\n");

    ui->textEdit_qss->append(qss);
}

void MainWindow::onMkMenuBar()
{
    QString qss = QString(
                "/*---------QMenuBar----------*/\n"
                "QMenuBar{\n"
                "   background:$4;\n"
                "   border:1px solid $5;\n"
                "}\n"
                "QMenuBar::item{\n"
                "   spacing:3px;\n"
                "   padding:4px 6px;\n"
                "   background:transparent;\n"
                "}\n"
                "QMenuBar::item:selected{\n"
                "   background:$bak6_1;\n"
                "}\n"
                "QMenuBar::item:pressed{\n"
                "   background:$bak6_2;\n"
                "}\n");

    ui->textEdit_qss->append(qss);
}

void MainWindow::onMkMenu()
{
    QString qss = QString(
                "/*---------QMenu----------*/\n"
                "QMenu,\n"
                "QMenu::item:disabled:select{\n"
                "   background:$7;\n"
                "}\n"
                "QMenu::separator{\n"
                "   height:1px;\n"
                "   background:$4;\n"
                "}\n"
                "QMenu::item:selected{\n"
                "   background:$bak6_1;\n"
                "}\n"
                "QMenu::indeicator,\n"
                "QMenu::icon{\n"
                "   width:0.8em;\n"
                "   height:0.8em;\n"
                "   padding:5px 0px;\n"
                "}\n");

    ui->textEdit_qss->append(qss);
}




