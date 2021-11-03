#include "skinwidget.h"
#include <QHBoxLayout>
#include <QApplication>
#include <QResource>
#include <QFile>
#include <QDir>
#include <QDebug>

//存放rcc文件的文件夹名称
#define RCC_DIR_NAME "rcc"
//qrc资源文件里用于存放QSS的前缀
#define QRC_QSS_PREFIX "stylesheet"


SkinWidget::SkinWidget(QWidget *parent) : QWidget(parent)
{
    initUI();
    initSkin();
}


void SkinWidget::initUI()
{
    QHBoxLayout* hLayout = new QHBoxLayout();
    setLayout(hLayout);

    m_label = new QLabel(tr("Skin:"),this);
    hLayout->addWidget(m_label);

    m_comboBox = new QComboBox(this);
    hLayout->addWidget(m_comboBox);
    connect(m_comboBox,SIGNAL(currentIndexChanged(int)),
            this, SLOT(onSwitch(int)));

}

void SkinWidget::initSkin()
{
    //添加1个空的
    m_qssString.push_back("");
    m_comboBox->addItem("No Skin (native)", "");

    //遍历文件夹的rcc，添加内置的
    QString rccPath = QApplication::applicationDirPath()+"/" + RCC_DIR_NAME + "/";
    QFileInfoList rccFiles = QDir(rccPath).entryInfoList(QStringList("*.rcc"),
                                                      QDir::Files | QDir::Readable, QDir::Name);


    for (int i = 0; i < rccFiles.length(); ++i) {
        QFileInfo info = rccFiles[i];
        QString rccFilePath = info.absoluteFilePath();
        QString skinName = info.baseName();
        QString skinFilePath = QString(":/%1/%2.qss")
                .arg(QRC_QSS_PREFIX)
                .arg(skinName);

        qDebug() << "Load skin:" << skinName;
        //切换rcc资源
        QResource::registerResource(rccFilePath);
        //
        appendSkin(skinName,skinFilePath,rccFilePath);

    }
}

void SkinWidget::onSwitch(int index)
{
    //切换rcc资源
    QString rccFile = m_comboBox->currentData().toString();
    QResource::registerResource(rccFile);


    //切换QSS
    assert(index < m_qssString.size());
    QString qssContent = m_qssString.at(index);
    qApp->setStyleSheet(qssContent);
}



void SkinWidget::appendSkin(const QString &skinName,
                            const QString &skinFilePath,
                            const QString &rccFilePath)
{
    //读取qss内容
    QString stylesheet;
    QFile qss(skinFilePath);
    if (!QFile::exists(skinFilePath)) {
        qDebug() << tr("Can not find skin file. (%1)").arg(skinFilePath);
        return;
    }

    if (qss.open(QFile::ReadOnly)) {
        stylesheet = tr(qss.readAll());
    } else {
        qDebug() << tr("Failed to read skin file. (%1)").arg(skinFilePath);
        return;
    }
    qss.close();

    //添加
    m_qssString.push_back(stylesheet);
    m_comboBox->addItem(skinName, rccFilePath);
}
