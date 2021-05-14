#include "singleton.h"
#include <iostream>

int main ()
{
    Singleton::getInstance().setA(5);
    Singleton::getInstance().setB(2.4);

    std::cout << Singleton::getInstance().getA() << std::endl;
    std::cout << Singleton::getInstance().getB() << std::endl;
}