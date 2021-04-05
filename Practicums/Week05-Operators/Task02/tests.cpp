#define CATCH_CONFIG_MAIN
#include "..\..\..\catch2\catch2.hpp"
#include "washingMachine.h"

TEST_CASE ("operator >")
{
    WashingMachine wm1("pesho", "3945", 10, 5, 5), wm2("rado", "1212", 8, 4, 3);

    SECTION ("larger mass laundry")
    {
        REQUIRE (wm1 > wm2);
    }

    SECTION ("equal mass laundry, lower electrical consumption")
    {
        wm1.setMassLaundry(8);
        wm1.setElConsumption(3);
        REQUIRE (wm1 > wm2);
    }

    SECTION ("equal mass laundry and electrical consumption, lower eater consumption")
    {
        wm1.setMassLaundry(8);
        wm1.setElConsumption(4);
        wm1.setWaterConsuption(2);
        REQUIRE (wm1 > wm2);
    }
}