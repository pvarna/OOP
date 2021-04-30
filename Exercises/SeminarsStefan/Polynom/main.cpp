#include <iostream>
#include "polynom.h"

int main ()
{
    Polynom p1, p3; //5x^2 + 4x + 3
    Polynom p2; //x^3 + x^2 + 7

    p1.setCoefficient(2, 5);
    p1.setCoefficient(1, 4);
    p1.setCoefficient(0, 3);
    p1.print();

    p2.setCoefficient(2, 1);
    p2.setCoefficient(0, 7);
    p2.setCoefficient(3, 1);

    //p1 += p2;
    //p1.print();

    (p1 - p2).print();

    p3.setCoefficient(2, 5);
    p3.setCoefficient(1, 4);
    p3.setCoefficient(0, 3);

    /*if (p1 == p3)
    {
        std::cout << "pesho";
    }
    if (p1 != p2)
    {
        std::cout << "!pesho";
    }*/

    //(p1 - p1).print();

    Polynom p1Derivative = p1.getDerivative();
    p1Derivative.print();

    Polynom p4;
    //p4.setCoefficient(0, 3);
    p4.getDerivative().print();
    return 0;
}