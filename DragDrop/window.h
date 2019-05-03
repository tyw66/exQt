#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "listcontainer.h"
#include"dropbutton.h"

namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

private:
    Ui::Window *ui;
    //ListContainer *listcontainer;
};

#endif // WINDOW_H
