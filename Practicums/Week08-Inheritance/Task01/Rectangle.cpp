#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle(double width, double height) : Shape("Rectangle")
{
    this->width = width;
    this->height = height;
}

Rectangle::Rectangle(double width, double height, std::string type) : Shape(type)
{
    this->width = width;
    this->height = height;
}

void Rectangle::print()
{
    Shape::print();
    std::cout << "Width: " << this->width << std::endl;
    std::cout << "Height: " << this->height << std::endl;
}