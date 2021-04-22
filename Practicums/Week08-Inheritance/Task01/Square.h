#pragma once

#include "Rectangle.h"

class Square : public Rectangle
{
public:
    Square(double side);

    void print();
};