#ifndef PROGRESSVIEW_H
#define PROGRESSVIEW_H

#include <QWidget>
#include <QFuture>
#include <QVBoxLayout>
class ProgressView : public QWidget
{
    Q_OBJECT
public:
    explicit ProgressView(QWidget *parent = nullptr);


    void addTask(const QFuture<void> &future, const QString &title);

private:
    QVBoxLayout* m_layout;

};

#endif // PROGRESSVIEW_H
