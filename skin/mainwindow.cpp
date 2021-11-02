#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initSkin();
    initIcon();

    connect(ui->comboBox_skin,SIGNAL(currentIndexChanged(int)),
            this, SLOT(onSwitchStyleSheet(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSwitchStyleSheet(int index)
{
    assert(index < m_qssString.size());
    QString qssContent = m_qssString.at(index);
    qApp->setStyleSheet(qssContent);
}

void MainWindow::initSkin()
{
    //添加1个空的
    m_qssString.push_back("");
    ui->comboBox_skin->addItem("No Skin!", "");

    //添加内置的
    appendSkin(tr("LightBlue"),":/stylesheet/lightblue.qss");
    appendSkin(tr("DarkOrang"),":/stylesheet/darkOrange.qss");
}

void MainWindow::initIcon()
{
    ui->toolButton_A->setIcon(QIcon(":/icons/save.png"));
    ui->toolButton_A->setIconSize(QSize(48,48));
    ui->toolButton_B->setIcon(QIcon(":/icons/close_project.png"));
    ui->toolButton_B->setIconSize(QSize(48,48));

}

void MainWindow::appendSkin(const QString &skinName,
                            const QString &skinFilePath)
{
    //读取qss内容
    QString stylesheet;
    QFile qss(skinFilePath);
    if (!QFile::exists(skinFilePath)) {
        return;
    }

    if (qss.open(QFile::ReadOnly)) {
        stylesheet = tr(qss.readAll());
    } else {
        return;
    }
    qss.close();

    //添加
    m_qssString.push_back(stylesheet);
    ui->comboBox_skin->addItem(skinName, stylesheet);
}

