#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //切换皮肤响应
    void onSwitchStyleSheet(int index);


private:
    void initSkin();

    void initIcon();

    void appendSkin(const QString &skinName,
                    const QString& skinFilePath);



private:
    Ui::MainWindow *ui;

    QList<QString> m_qssString;


};
#endif // MAINWINDOW_H
