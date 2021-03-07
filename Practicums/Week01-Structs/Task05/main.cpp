#include "functions.h"
#include <iostream>

int main ()
{
    Rectangular rectangular1, rectangular2;

    std::cout << "Rectangular #1" << std::endl;
    rectangular1.readRectangular();
    std::cout << "Rectangular #2" << std::endl;
    rectangular2.readRectangular();

    Point point;

    std::cout << "Point #1" << std::endl;
    point.readPoint();

    if (rectangular1.isPointContained(point))
    {
        std::cout << "The point is contained in Rectangular #1" << std::endl;
    }
    else
    {
        std::cout << "The point is not contained in Rectangular #1" << std::endl;
    }
    if (rectangular2.isPointContained(point))
    {
        std::cout << "The point is contained in Rectangular #2" << std::endl;
    }
    else
    {
        std::cout << "The point is not contained in Rectangular #2" << std::endl;
    }

    if (doRectanglesIntersect(rectangular1, rectangular2))
    {
        std::cout << "The rectangles intersect" << std::endl;
    }
    else
    {
        std::cout << "The rectangles do not intersect" << std::endl;
    }

    return 0;
}