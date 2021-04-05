#define CATCH_CONFIG_MAIN
#include "..\..\..\catch2\catch2.hpp"
#include "time.h"

TEST_CASE ("operator ==")
{
    Time time1, time2(0,0), time3;

    SECTION ("obvious test")
    {
        REQUIRE (time1 == time3);
    }
    SECTION ("compare default constructor and constructor with parameters")
    {
        REQUIRE (time1 == time2);
    }

    time1.setHours(5);
    time1.setMinutes(10);
    time2.setHours(5);
    time2.setMinutes(10);
    SECTION ("compare equal times")
    {
        REQUIRE (time1 == time2);   
    }

    time2.setMinutes(15);
    SECTION ("compare different times")
    {
        REQUIRE_FALSE (time1 == time2);   
    }
}

TEST_CASE ("operator +=")
{
    Time time1, time2, time3;

    SECTION ("obvious test")
    {
        time1 += time2;
        REQUIRE (time1 == time3);
    }   

    time1.setHours(2);
    time1.setMinutes(20);
    time2.setHours(3);
    time2.setMinutes(30);
    time3.setHours(5);
    time3.setMinutes(50);

    SECTION ("normal addition")
    {
        time1 += time2; // 2:20 += 3:30 == 5:50
        REQUIRE (time1 == time3);
    }

    SECTION ("addition with more than 60 minutes")
    {
        time1.setHours(5);
        time1.setMinutes(50);
        time1 += time2; // 5:50 += 3:30 == 9:20
        time3.setHours(9);
        time3.setMinutes(20);
        REQUIRE (time1 == time3);
    }

    SECTION ("addition with more tham 23 hours")
    {
        time1.setHours(9);
        time1.setMinutes(20);
        time2.setHours(20);
        time2.setMinutes(50);
        time1 += time2; // 9:20 += 20:50 == 6:10
        time3.setHours(6);
        time3.setMinutes(10);
        REQUIRE (time1 == time3);
    }
}

TEST_CASE ("operator >")
{
    Time time1(10, 30), time2(9, 20);

    SECTION ("obvious test")
    {
        REQUIRE (time1 > time2);
    }

    SECTION ("check equality")
    {
        time2.setHours(10);
        time2.setMinutes(30);
        REQUIRE_FALSE (time1 > time2);
    }

    SECTION ("check equal hours")
    {
        time2.setHours(10);
        time2.setMinutes(10);
        REQUIRE (time1 > time2);
    }
}