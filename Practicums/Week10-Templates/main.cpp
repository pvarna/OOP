#include "list.h"
#include "order.h"
#include "point.h"

int main ()
{
    Order<Point> points;

    points.push_back(Point(1, 2));
    points.push_back(Point(0, 2));
    points.push_back(Point(1, 1));
    points.push_back(Point(-5, 3));
    points.push_back(Point(10, 1));

    points.writeIntoFile("points.txt");

    Order<Point> copy;

    copy.readFromFile("points.txt");

    for (std::size_t i = 0; i < copy.getSize(); ++i)
    {
        std::cout << copy[i] << std::endl;
    }
    
    return 0;
}