#include <iostream>
#include "Shape.h"

Shape::Shape(std::string type) : type(type) {}

void Shape::print()
{
    std::cout << "Type: " << this->type << std::endl;
}