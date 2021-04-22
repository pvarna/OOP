#include <iostream>
#include "Triangle.h"

Triangle::Triangle(double side1, double side2, double side3) : Shape("Triangle")
{
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}

void Triangle::print()
{
    Shape::print();
    std::cout << "Side 1: " << this->side1 << std::endl;
    std::cout << "Side 2: " << this->side2 << std::endl;
    std::cout << "Side 3: " << this->side3 << std::endl;

}