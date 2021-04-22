#pragma once

#include <string>
#include "Rectangle.h"

class ColoredRectangle : public Rectangle
{
protected:
    std::string color;

public:
    ColoredRectangle(double width, double height, std::string color);

    void print();
};