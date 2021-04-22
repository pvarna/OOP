#include <iostream>
#include "Square.h"

Square::Square(double side) : Rectangle(side, side, "Square") {}

void Square::print()
{
    Rectangle::print();
}