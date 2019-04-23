#include "mainwindow.h"
#include <QPluginLoader>
#include <QMessageBox>
#include <QDir>
#include <QPainter>


Mainwindow::Mainwindow(QWidget *parent) : QMainWindow(parent)
{
    //初始化
    setWindowTitle(tr("Image"));
    setGeometry(200,150,1400,865);

    // 加载插件，填充m_interface对象
    if(!loadPlugin()){
        QMessageBox::information(this, "Error","Could not load the plugin.");
        return;
    }

    //重绘
    m_image = QImage(256,256,QImage::Format_RGB32);
    m_interface->paintImg(m_image);
    update();
}

bool Mainwindow::loadPlugin()
{
    QDir pluginDir("./plugin");

    foreach (QString fileName, pluginDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();  //加载
        if(plugin){
            m_interface = qobject_cast<ImgInterface*>(plugin);//类型转换
            if(m_interface)
                return true;
        }
    }
    return false;
}


void Mainwindow::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawImage(ev->rect(),m_image);
}
