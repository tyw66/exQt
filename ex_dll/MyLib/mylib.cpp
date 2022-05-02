#include "mylib.h"
#include "hello.h"
MyLib::MyLib()
{
}

void MyLib::hi()
{
    h = QSharedPointer<Hello>(new Hello());
    if(!h.isNull()){
        h->sayHello();
    }
}
