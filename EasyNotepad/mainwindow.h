#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QString currentFile;

    void save(QString fileName);

private slots:
    void newFile();
    void  openFile();
    void saveFile();
    void saveFileAs();

//   void  cut();
//    void copy();
//    void parse();
   void selectAll();
 //  void findFile();

//    void About();
   void WindowModified();
};

#endif // MAINWINDOW_H
