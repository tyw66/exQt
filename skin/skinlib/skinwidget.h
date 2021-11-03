#ifndef SKINWIDGET_H
#define SKINWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QSettings>

#include "skinwidget_global.h"

class SKINWIDGETSHARED_EXPORT SkinWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SkinWidget(QWidget *parent = nullptr);


private slots:
    //切换皮肤响应
    void onSwitch(int);


private:
    ///初始化UI
    inline void initUI();
    ///初始化信号槽
    inline void initConnect();
    ///初始化皮肤
    void initSkinItem();

    ///读取qss内容
    QString readStyleSheet(const QString& skinFilePath);

    ///读取配置文件中的当前皮肤 位于"skin"关键字
    void readSkin();
    /// 向配置文件中的当前皮肤 位于"skin"关键字
    void writeSkin();

signals:
    void skinChanged();

private:
    QLabel* m_label;
    QComboBox* m_comboBox;


    QSettings* m_settings;
};

#endif // SKINWIDGET_H
