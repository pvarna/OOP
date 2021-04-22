#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "ColoredRectangle.h"
#include "Square.h"
#include "Triangle.h"

int main ()
{
    Rectangle rec(2, 3);
    ColoredRectangle cRec(5, 6, "red");
    Square sq(2);
    Triangle tr(3, 4, 5);

    rec.print();
    cRec.print();
    sq.print();
    tr.print();

    return 0;
}