#include <iostream>

using namespace std;
class A{
public:
    A(){}
    A(int a){ std::cout<< a << std::endl;}

    void print();


};


void A::print()
{
    std::cout<< "hhhh"<< std::endl;
}

int main()
{
    A aa;
    A *a = NULL;
    a->print();
}

