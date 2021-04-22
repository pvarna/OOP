#pragma once

#include "Shape.h"

class Triangle : public Shape
{
protected:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double side1, double side2, double side3);

    void print();
};