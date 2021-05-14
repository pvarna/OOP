#include "point.h"

Point::Point()
{
    this->x = 0.0;
    this->y = 0.0;
}

Point::Point(double x, double y)
{
    this->x = x;
    this->y = y;
}

bool Point::operator == (const Point& other) const
{
    return this->x == other.x && this->y == other.y;
}

bool Point::operator > (const Point& other) const
{
    return this->x > other.x || (this->x == other.x && this->y > other.y);
}

std::istream& operator >> (std::istream& in, Point& point)
{
    in >> point.x >> point.y;

    return in;
}

std::ostream& operator << (std::ostream& out, const Point& point)
{
    out << point.x << " " << point.y;

    return out;
}