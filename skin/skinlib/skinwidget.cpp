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
//配置文件中皮肤的关键字
#define INI_KEY_SKIN "skin"
//配置文件路径
#define INIFILE_PATH "./settings.ini"

SkinWidget::SkinWidget(QWidget *parent) : QWidget(parent)
{
    m_settings = new QSettings(INIFILE_PATH,QSettings::IniFormat);

    initUI();
    initSkinItem();

    initConnect();
    readSkin();
}

void SkinWidget::initUI()
{
    QHBoxLayout* hLayout = new QHBoxLayout();
    setLayout(hLayout);

    m_label = new QLabel(tr("Skin:"),this);
    hLayout->addWidget(m_label);

    m_comboBox = new QComboBox(this);
    hLayout->addWidget(m_comboBox);
}

void SkinWidget::initConnect()
{
    connect(m_comboBox,SIGNAL(currentIndexChanged(int)),
            this, SLOT(onSwitch(int)));
}

void SkinWidget::initSkinItem()
{
    //添加1个空的皮肤
    QString skinNameNative = "(native)";
    m_comboBox->addItem(skinNameNative, "");

    //遍历文件夹的rcc，添加内置的皮肤
    QString rccPath = QApplication::applicationDirPath()+"/" + RCC_DIR_NAME + "/";
    QFileInfoList rccFiles = QDir(rccPath).entryInfoList(QStringList("*.rcc"),
                                                         QDir::Files | QDir::Readable, QDir::Name);

    for (int i = 0; i < rccFiles.length(); ++i) {
        QFileInfo info = rccFiles[i];

        //m_comboBox添加
        QString skinName = info.baseName();
        QString rccFilePath = info.absoluteFilePath();
        m_comboBox->addItem(skinName, rccFilePath);
    }

    //根据配置文件，添加扩展配置的皮肤TODO

}

QString SkinWidget::readStyleSheet(const QString &qssFilePath)
{
    QString stylesheet;
    QFile qss(qssFilePath);
    if (!QFile::exists(qssFilePath)) {
        qDebug() << tr("Can not find skin file. (%1)").arg(qssFilePath);
        return stylesheet;
    }

    if (qss.open(QFile::ReadOnly)) {
        stylesheet = tr(qss.readAll());
    } else {
        qDebug() << tr("Failed to read skin file. (%1)").arg(qssFilePath);
        return stylesheet;
    }
    qss.close();

    return stylesheet;
}


void SkinWidget::onSwitch(int index)
{
    //更新配置文件
    writeSkin();

    //向外部发信号
    emit skinChanged();
}

void SkinWidget::readSkin()
{
    //读取配置文件中记录的当前皮肤，并切换，如果不存在，切换为第一个。
    if(m_settings){
        QString skinName = m_settings->value(INI_KEY_SKIN).toString();
        int index = m_comboBox->findText(skinName);
        m_comboBox->setCurrentIndex(index == -1 ? 0 : index);
    }
    else{
        m_comboBox->setCurrentIndex(0);
    }

    //启动时动态加载RCC资源[只执行1次]
    QString rccFile = m_comboBox->currentData().toString();
    QResource::registerResource(rccFile);

    //加载QSS
    QString skinName = m_comboBox->currentText();
    QString skinFilePath = QString(":/%1/%2.qss")
            .arg(QRC_QSS_PREFIX).arg(skinName);

    qApp->setStyleSheet(readStyleSheet(skinFilePath));
}

void SkinWidget::writeSkin()
{
    //向配置文件中更新当前皮肤的记录
    if(m_settings){
        QString skinName = m_comboBox->currentText();
        m_settings->setValue(INI_KEY_SKIN, skinName);
    }
}
