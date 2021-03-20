#include "triangle.h"
#include <iostream>

int main ()
{
    Triangle tr1;
    tr1.input();

    std::cout << "Perimeter: " << tr1.perimeter() << std::endl;
    std::cout << "Area: " << tr1.area() << std::endl;

    return 0;
}