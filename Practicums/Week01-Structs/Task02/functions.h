struct Point
{
    double x;
    double y;

    void readPoint();
    void printPoint();
    double distanceToCenter();
};

double distanceBetweenPoints(Point point1, Point point2);
