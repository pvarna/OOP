#include "singleton.h"

Singleton::Singleton()
{
    this->a = 0;
    this->b = 0.0;  
}

Singleton& Singleton::getInstance()
{
    static Singleton object;

    return object;
}

int Singleton::getA() const
{
    return this->a;
}
double Singleton::getB() const
{
    return this->b;
}

void Singleton::setA(int a)
{
    this->a = a;
}

void Singleton::setB(double b)
{
    this->b = b;
}