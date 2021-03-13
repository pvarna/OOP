#define CATCH_CONFIG_MAIN
#include "../catch2/catch2.hpp"
#include "functions.h"

TEST_CASE("Functions", "[functions]")
{
    Rectangular rec1, rec2;
    Point point1;

    SECTION("test if a point is contained in a rectangular #1")
    {
        rec1.upperLeft.x = 0;
        rec1.upperLeft.y = 5;
        rec1.lowerRight.x = 6;
        rec1.lowerRight.y = 0;

        point1.x = 2;
        point1.y = 3;

        REQUIRE(rec1.isPointContained(point1) == true);
    }

    SECTION("test if a point is contained in a rectangular #2")
    {
        point1.x = 7;
        point1.y = 0;

        REQUIRE(rec1.isPointContained(point1) == false);
    }

    SECTION("test if a point is contained in a rectangular #3")
    {
        point1.x = 3;
        point1.y = 5;

        REQUIRE(rec1.isPointContained(point1) == true);
    }

    SECTION("test is two rectangulars intersect #1")
    {
        rec2.upperLeft.x = 4;
        rec2.upperLeft.y = 8;
        rec2.lowerRight.x = 10;
        rec2.lowerRight.y = 4;

        REQUIRE(doRectanglesIntersect(rec1, rec2) == true);
    }

    SECTION("test is two rectangulars intersect #1")
    {
        rec2.upperLeft.x = 8;
        rec2.upperLeft.y = 8;
        rec2.lowerRight.x = 10;
        rec2.lowerRight.y = 4;

        REQUIRE(doRectanglesIntersect(rec1, rec2) == false);
    }
}