#ifndef SKINWIDGET_H
#define SKINWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include "skinwidget_global.h"


class SKINWIDGETSHARED_EXPORT SkinWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SkinWidget(QWidget *parent = nullptr);


private slots:
    //切换皮肤响应
    void onSwitch(int index);


private:
    void initUI();
    void initSkin();


    void appendSkin(const QString& skinName,
                    const QString& skinFilePath,
                    const QString& rccFilePath);


private:
    QLabel* m_label;
    QComboBox* m_comboBox;

    QList<QString> m_qssString;

};

#endif // SKINWIDGET_H
