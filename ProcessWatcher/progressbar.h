#ifndef PROGRESSVIEW_H
#define PROGRESSVIEW_H

#include <QWidget>
#include <QFuture>
#include <QVBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QPointer>

class ProgressBar : public QWidget
{
    Q_OBJECT
public:
    explicit ProgressBar(QWidget *parent = nullptr);





private:
    QVBoxLayout* m_layout;
    QGraphicsOpacityEffect *m_opacityEffect;
    QPointer<QPropertyAnimation> m_opacityAnimation;
};


class ProgressMananger{
public:
    static void addTask(const QFuture<void> &future, const QString &title);


};


#endif // PROGRESSVIEW_H
