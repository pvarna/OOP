#pragma once

#include <iostream>

class Point
{
private:
    double x;
    double y;

public:
    Point();
    Point(double x, double y);

    bool operator > (const Point& other) const;

    bool operator == (const Point& other) const;
    friend std::istream& operator >> (std::istream& in, Point& point);
    friend std::ostream& operator << (std::ostream& out, const Point& point);
};