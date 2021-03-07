#include "functions.h"
#include <iostream>

void Point::readPoint()
{
    std::cout << "x = ";
    std::cin >> x;
    std::cout << "y = ";
    std::cin >> y;
}

void Rectangular::readRectangular()
{
    std::cout << "Enter the coordinates of the upper left vertex of the rectangular:" << std::endl;
    upperLeft.readPoint();

    std::cout << "Enter the coordinates of the lower right vertex of the rectangular:" << std::endl;
    lowerRight.readPoint();
}

bool Rectangular::isPointContained(Point point)
{
    return ((point.x >= upperLeft.x && point.x <= lowerRight.x) && (point.y >= lowerRight.y && point.y <= upperLeft.y));
}

bool doRectanglesIntersect(Rectangular rectangular1, Rectangular rectangular2)
{
    if (std::max(rectangular1.upperLeft.x, rectangular2.upperLeft.x) > std::min(rectangular1.lowerRight.x, rectangular2.lowerRight.x))
    {
        return false;
    }

    if (std::max(rectangular1.lowerRight.y, rectangular2.lowerRight.y) > std::min(rectangular1.upperLeft.y, rectangular2.upperLeft.y))
    {
        return false;
    }

    return true;
}