#define CATCH_CONFIG_MAIN
#include "..\..\..\catch2\catch2.hpp"
#include "time.h"

//Time time1(11, 30), time2(11, 30), time3(0, 0), time4;

TEST_CASE ("Time")
{
    Time time1(11, 30), time2(11, 30), time3(0, 0), time4;

    SECTION ("operator ==")
    {
        REQUIRE (time1 == time2);
        REQUIRE_FALSE (time1 == time3);
        REQUIRE (time3 == time4);
    }

    SECTION ("operator +=")
    {
        Time result1(23, 0), result2(10, 30);

        time1 += time2;
        REQUIRE (time1 == result1);

        time1 += time3;
        REQUIRE (time1 == result1);

        time1 += time2;
        REQUIRE (time1 == result2);
    }

}