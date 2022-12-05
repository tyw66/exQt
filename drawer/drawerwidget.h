#ifndef DRAWERWIDGET_H
#define DRAWERWIDGET_H

#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class DrawerWidget; }
QT_END_NAMESPACE

class DrawerWidget : public QWidget
{
    Q_OBJECT
public:
    DrawerWidget(QWidget *parent = nullptr);
    ~DrawerWidget();

    void setTitle(const QString& title);

    void addWidget(QWidget* widget);

private slots:
    void onToggle();

private:
    Ui::DrawerWidget *ui;
    QLabel* m_label;

    bool m_isOpening;
    int m_height;
};
#endif // DRAWERWIDGET_H

