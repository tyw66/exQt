#include "langwidget.h"
#include <QDebug>
#include <QLocale>

LangDialog::LangDialog(QWidget *parent) : QDialog(parent)
{
    //
    setWindowTitle(tr("Language"));

    //语言列表框
    m_langListWidget = new QListWidget(this);


    //语言列表项
    QListWidgetItem* item_enUS = new QListWidgetItem(tr("English"),m_langListWidget);
    item_enUS->setData(Qt::UserRole, QLocale::English);
    QListWidgetItem* item_zhCN = new QListWidgetItem(tr("Chinese"),m_langListWidget);
    item_zhCN->setData(Qt::UserRole, QLocale::Chinese);
    QListWidgetItem* item_jaJP = new QListWidgetItem(tr("Japanese"),m_langListWidget);
    item_jaJP->setData(Qt::UserRole, QLocale::Japanese);

    //按钮
    m_buttonOk = new QPushButton(tr("OK"), this);
    m_buttonCancel= new QPushButton(tr("Cancel"), this);
    connect(m_buttonOk, SIGNAL(clicked()), this, SLOT(onSwithLanguage()));
    connect(m_buttonCancel, SIGNAL(clicked()), this, SLOT(close()));

    //布局
    m_mainLayout = new QGridLayout(this);
    m_mainLayout->addWidget(m_langListWidget,0,0,1,2);
    m_mainLayout->addWidget(m_buttonOk,1,0,1,1);
    m_mainLayout->addWidget(m_buttonCancel,1,1,1,1);
}

void LangDialog::onSwithLanguage()
{
    QLocale::Language lang = (QLocale::Language)m_langListWidget->currentItem()->data(Qt::UserRole).toInt();
    switch (lang) {
    case QLocale::Chinese:{
        qDebug() << tr("Swith laguage to Chinise.");
        //to complete..
        break;
    }
    case QLocale::Japanese:{
        qDebug() << tr("Swith laguage to Japanese.");
        //to complete..
        break;
    }
    case QLocale::English:{
        qDebug() << tr("Swith laguage to English.");
        //to complete..
        break;
    }
    default:
        break;
    }



}

