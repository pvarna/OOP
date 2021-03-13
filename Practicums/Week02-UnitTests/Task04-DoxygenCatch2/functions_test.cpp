#define CATCH_CONFIG_MAIN
#include "..\catch2\catch2.hpp"
#include "functions.h"
#include <cmath>

TEST_CASE("Average speed", "[speed]")
{
    Runner runner;
    runner.results[0] = 9000;
    runner.results[1] = 9200;
    runner.results[2] = 9400;
    runner.results[3] = 9600;
    runner.results[4] = 9800;
    runner.results[5] = 9000;
    runner.results[6] = 10000;
    runner.results[7] = 8500;
    runner.results[8] = 9000;
    runner.results[9] = 9500;
    runner.results[10] = 12000;
    runner.results[11] = 7800;

    SECTION("test")
    {
        REQUIRE(fabs(runner.averageSpeed() - 16.08511) < 0.0001);
    }   
}

TEST_CASE("Times RunnerA has beaten RunnerB", "[times beaten]")
{
    Runner runnerA, runnerB;
    runnerA.results[0] = 9000; 
    runnerA.results[1] = 9200; //1
    runnerA.results[2] = 9400;
    runnerA.results[3] = 9600;
    runnerA.results[4] = 9800; //2
    runnerA.results[5] = 9000; //3
    runnerA.results[6] = 10000; //4
    runnerA.results[7] = 8500; 
    runnerA.results[8] = 9000;
    runnerA.results[9] = 9500; //5
    runnerA.results[10] = 12000; //6
    runnerA.results[11] = 7800; //7

    runnerB.results[0] = 9000;
    runnerB.results[1] = 9300;
    runnerB.results[2] = 9300; //1
    runnerB.results[3] = 9600;
    runnerB.results[4] = 9900;
    runnerB.results[5] = 9100;
    runnerB.results[6] = 11000;
    runnerB.results[7] = 8400; //2
    runnerB.results[8] = 9000;
    runnerB.results[9] = 9600;
    runnerB.results[10] = 13000;
    runnerB.results[11] = 7900;

    SECTION("test #1")
    {
        REQUIRE(runnerA.beatNtime(runnerB) == 7);
    }

    SECTION("test #2")
    {
        REQUIRE(runnerB.beatNtime(runnerA) == 2);
    }
}