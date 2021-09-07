#ifndef SIGNALHUB_H
#define SIGNALHUB_H

#include <QObject>

/**
 * @brief 系统状态改变的情形提炼成一个个信号，放在这个独立的模块中，
 */
class SignalHub : public QObject
{
    Q_OBJECT
public:
    static SignalHub* inst();

    //for Qt4
    void emitCurrentSelectIDChanged(const QString& msg);

signals:
    ///信号1
    void currentSelectIDChanged(const QString& msg);

private:
    explicit SignalHub(QObject *parent = NULL);
    static SignalHub* m_self;
};

#endif // SIGNALHUB_H
