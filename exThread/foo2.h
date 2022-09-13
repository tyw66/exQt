#ifndef FOO2_H
#define FOO2_H
#include <QObject>

class Foo2 : public QObject
{
    Q_OBJECT
public:
    Foo2();

public slots:
    void onClock();

signals:
    void resultReady(const QString &s);

};

#endif // FOO2_H
