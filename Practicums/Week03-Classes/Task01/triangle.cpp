#include "triangle.h"
#include <iostream>
#include <cmath>

bool Triangle::validate()
{
    bool areSidesPositive = (this->sideA > 0 && this->sideB > 0 && this->sideC > 0);

    double minSide = std::min(std::min(this->sideA, this->sideB), this->sideC);
    double maxSide = std::max(std::max(this->sideA, this->sideB), this->sideC);
    double middleSide = perimeter() - (minSide + maxSide);

    bool doesTriangleExist = (maxSide < minSide + middleSide);

    return areSidesPositive && doesTriangleExist;
}

void Triangle::input()
{
    int counter = 0;
    do
    {
        if (counter > 0)
        {
            std::cout << "Please enter valid sides of the triangle:" << std::endl;
        }
        std::cout << "Please enter Side A: ";
        std::cin >> this->sideA;
        std::cout << "Please enter Side B: ";
        std::cin >> this->sideB;
        std::cout << "Please enter Side C: ";
        std::cin >> this->sideC;
        ++counter;
    } while (!validate());
    
}

double Triangle::perimeter()
{
    return this->sideA + this->sideB + this->sideC;
}

double Triangle::area()
{
    double semiPerimeter = perimeter()/2;
    return sqrt(semiPerimeter*(semiPerimeter-this->sideA)*(semiPerimeter-this->sideB)*(semiPerimeter-this->sideC));
}