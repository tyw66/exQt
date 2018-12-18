#ifndef TOYDIALOG_H
#define TOYDIALOG_H

#include <QMainWindow>
#include <QMenu>

namespace Ui {
class ToyDialog;
}

class ToyDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit ToyDialog(QWidget *parent = 0);
    ~ToyDialog();

private:
    Ui::ToyDialog *ui;

    QMenu* menu;
    QMenu* menu_001;

private slots:
    void slotHello();

};

#endif // TOYDIALOG_H
