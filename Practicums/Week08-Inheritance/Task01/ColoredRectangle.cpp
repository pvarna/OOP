#include <iostream>
#include "ColoredRectangle.h"

ColoredRectangle::ColoredRectangle(double width, double height, std::string color)
                                    : Rectangle(width, height, "Colored Rectangle")
{
    this->color = color;
}

void ColoredRectangle::print()
{
    Rectangle::print();
    std::cout << "Color: " << this->color << std::endl;
}