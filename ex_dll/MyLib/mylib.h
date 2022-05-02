#ifndef MYLIB_H
#define MYLIB_H

#include <QSharedPointer>
#include "MyLib_global.h"

class Hello;
class MYLIB_EXPORT MyLib
{
public:
    MyLib();

    void hi();

private:
    QSharedPointer<Hello> h;
};

#endif // MYLIB_H
