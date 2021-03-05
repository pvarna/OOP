#include "functions.h"
#include <iostream>

int main ()
{
    Point point1, point2;

    point1.readPoint();
    point2.readPoint();

    std::cout << std::endl;

    point1.printPoint();
    point2.printPoint();

    std::cout << std::endl;

    std::cout << point1.distanceToCenter() << std::endl;
    std::cout << point2.distanceToCenter() << std::endl;

    std::cout << std::endl;

    std::cout << distanceBetweenPoints(point1, point2) << std::endl;

    return 0;
}