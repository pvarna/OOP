#include "functions.h"
#include <iostream>
#include <cmath>

void Point::readPoint()
{
    std::cin >> x >> y;
}

void Point::printPoint()
{
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
}

double Point::distanceToCenter()
{
    return sqrt(x*x + y*y);
}

double distanceBetweenPoints(Point point1, Point point2)
{
    double a = fabs(point1.x - point2.x);
    double b = fabs(point1.y - point2.y);

    return sqrt(a*a + b*b);
}