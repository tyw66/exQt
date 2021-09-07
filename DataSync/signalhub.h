#ifndef SIGNALHUB_H
#define SIGNALHUB_H

#include <QObject>

class SignalHub : public QObject
{
    Q_OBJECT
public:
    static SignalHub* inst();

    //for Qt4
    void emitCurrentSelectIDChanged(int id);

signals:
    ///信号1
    void currentSelectIDChanged(int id);

private:
    explicit SignalHub(QObject *parent = NULL);
    static SignalHub* m_self;
};

#endif // SIGNALHUB_H
