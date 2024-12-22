#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Dynasty{
    QString name;
    int begin;
    int end;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onTimeChanged(int year);

private:
    QString makeInfo(int year, const QVector<Dynasty>& vec);

private:
    Ui::MainWindow *ui;
    QVector<Dynasty> m_dataChina;
    QVector<Dynasty> m_dataJapan;
    QVector<Dynasty> m_dataYilang;
    QVector<Dynasty> m_dataYidali;
    QVector<Dynasty> m_datayinguo;
    QVector<Dynasty> m_dataXila;

    void readData(const QString &filePath, QVector<Dynasty>& data);



};
#endif // MAINWINDOW_H
