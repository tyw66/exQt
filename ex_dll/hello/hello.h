#ifndef HELLO_H
#define HELLO_H
#include <QtGlobal>

#if defined (HELLO_LIB)
    #define HELLO_EXPORT Q_DECL_EXPORT
#else
    #define HELLO_EXPORT Q_DECL_IMPORT
#endif

class HELLO_EXPORT Hello{
public:
    void sayHello();

};

#endif // HELLO_H
