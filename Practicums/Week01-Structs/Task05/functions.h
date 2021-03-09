struct Point
{
    double x;
    double y;

    void readPoint();
};

struct Rectangular
{
    Point upperLeft;
    Point lowerRight;

    void readRectangular();
    void printRectangle();
    bool isPointContained(Point point);
};

bool doRectanglesIntersect(Rectangular rectangular1, Rectangular rectangular2);

