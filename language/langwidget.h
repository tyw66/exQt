#ifndef LANGWIDGET_H
#define LANGWIDGET_H

#include <QDialog>
#include<QListWidget>
#include <QPushButton>
#include <QGridLayout>

#include<QTranslator>
/**
 * @brief 语言选择对话框
 * @author tyw
 * @date 2019/04/22
 */
class LangDialog : public QDialog
{
    Q_OBJECT
public:
    explicit LangDialog(QWidget *parent = NULL);

private slots:
    void onSwithLanguage();

private:
    QListWidget* m_langListWidget;
    QPushButton* m_buttonOk ;
    QPushButton* m_buttonCancel;
    QGridLayout * m_mainLayout;
};

#endif // LANGWIDGET_H
