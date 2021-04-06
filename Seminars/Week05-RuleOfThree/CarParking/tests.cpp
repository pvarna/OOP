#define CATCH_CONFIG_MAIN
#include "..\..\..\catch2\catch2.hpp"
#include "parking.h"

TEST_CASE ("parking")
{
    Parking parking1;
    SECTION ("check initialization")
    {
        REQUIRE (parking1.getSize() == 0);
        REQUIRE (parking1.getCapacity() == 2);
    }

    Person pesho("Pesho", 10, true), sonche("Sonche", 19, false), mime("Mime", 19, true);
    Car car1(pesho, "Pegeout", "P PPPP P", GRAY), car2(sonche, "Renault", "S SSSS S", WHITE);
    
    parking1.addCar(car1);
    parking1.addCar(car2);

    SECTION ("check adding cars")
    {
        REQUIRE (parking1.getSize() == 2);
        REQUIRE (parking1.getCapacity() == 2);
    }

    Car car3(mime, "Audi", "M MMMM M", PURPLE);
    parking1.addCar(car3);

    SECTION ("check resizing")
    {
        REQUIRE (parking1.getSize() == 3);
        REQUIRE (parking1.getCapacity() == 4);
    }

    parking1.removeCar(0);
    
    SECTION ("check removing a car")
    {
        REQUIRE (parking1.getSize() == 2);
        REQUIRE (parking1.getCapacity() == 4);
    }

    parking1.removeCar(3);

    SECTION ("check removing a car with no such index")
    {
        REQUIRE (parking1.getSize() == 2);
        REQUIRE (parking1.getCapacity() == 4);
    }

    parking1.addCar(car1);

    SECTION ("check getOwnerByLicensePlate")
    {
        SECTION ("check normal comparison")
        {
            REQUIRE (parking1.getOwnerByLicensePlate("P PPPP P") == pesho);
            REQUIRE (parking1.getOwnerByLicensePlate("S SSSS S") == sonche);
            REQUIRE (parking1.getOwnerByLicensePlate("M MMMM M") == mime);
        }
        SECTION ("check if there is no such license plate")
        {
            Person nullPerson;
            REQUIRE (parking1.getOwnerByLicensePlate("X XXXX X") == nullPerson);
        }
    }

    SECTION ("check getCarsByOwner")
    {
        Car* result;
        size_t sizeResult;

        SECTION ("check finding only one car")
        {
            result = parking1.getCarsByOwner(sonche, sizeResult);
            REQUIRE (sizeResult == 1);
            REQUIRE (result[0] == car2);
            delete[] result;
        }

        Car newCar(sonche, "Mini Cooper", "S SSST S", PURPLE);
        parking1.addCar(newCar);

        SECTION ("check finding two cars")
        {
            result = parking1.getCarsByOwner(sonche, sizeResult);
            REQUIRE (sizeResult == 2);
            REQUIRE (result[0] == car2);
            REQUIRE (result[1] == newCar);   
            delete[] result;
        }

        Person newPerson;

        SECTION ("check not finding any cars")
        {
            result = parking1.getCarsByOwner(newPerson, sizeResult);
            REQUIRE (sizeResult == 0);
            REQUIRE (result == nullptr);
        }
    }
}