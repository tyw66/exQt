#ifndef DROPBUTTON_H
#define DROPBUTTON_H

#include <QPushButton>
#include<QDragEnterEvent>

class DropButton : public QPushButton
{
    Q_OBJECT
public:
    explicit DropButton(QWidget *parent = 0);
    ~DropButton();

private:
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);


signals:

public slots:
};

#endif // DROPBUTTON_H
