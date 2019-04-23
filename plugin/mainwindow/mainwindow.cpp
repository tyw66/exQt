#include "mainwindow.h"
#include <QPluginLoader>
#include <QMessageBox>
#include <QDir>

Mainwindow::Mainwindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(tr("Image"));
    setGeometry(300,300,1400,865);

    if(!loadPlugin()){
        QMessageBox::information(this, "Error","Could not load the plugin.");
        return;
    }

    m_image = QImage(W,H,QImage::Format_RGB32);
    renderImg(0,0);
}

bool Mainwindow::loadPlugin()
{
    QDir pluginDir("./plugin");

    foreach (QString fileName, pluginDir.entryList(QDir::Files)) {
        QPluginLoader pluginLoader(pluginDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if(plugin){
            m_interface = qobject_cast<ImgInterface*>(plugin);
            if(m_interface)
                return true;
        }
    }
    return false;
}

void Mainwindow::mouseMoveEvent(QMouseEvent *ev)
{
    mouse_posX = ev->x();
    mouse_posY = ev->y();

    renderImg(mouse_posX, mouse_posY);
}

void Mainwindow::renderImg(int x, int y)
{
    m_interface->paintImg(m_image);
    update();
}

void Mainwindow::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawImage(ev->rect(),m_image);
}
