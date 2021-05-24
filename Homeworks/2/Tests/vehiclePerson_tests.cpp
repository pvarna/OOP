#define CATCH_CONFIG_MAIN
#include "../catch2/catch2.hpp"
#include "../Headers/vehicle.h"
#include "../Headers/person.h"

TEST_CASE("vehicle getters")
{
    Vehicle yacht("V3945PK", "White yacht");
    Vehicle car("PL1234MN", "Red car");
    Vehicle plane("PL8765KG", "Black plane");

    SECTION("invalid registrations")
    {
        REQUIRE_THROWS(Vehicle("VVVVVVV", "yacht"));
        REQUIRE_THROWS(Vehicle("123456", "yacht"));
        REQUIRE_THROWS(Vehicle("VVV338PL", "yacht"));
        REQUIRE_THROWS(Vehicle("V39456P", "yacht"));
        REQUIRE_THROWS(Vehicle("", "yacht"));
    }

    REQUIRE(yacht.getRegistration() == "V3945PK");
    REQUIRE(yacht.getDescription() == "White yacht");
    REQUIRE(yacht.getOwner() == nullptr);
    REQUIRE(car.getRegistration() == "PL1234MN");
    REQUIRE(car.getDescription() == "Red car");
    REQUIRE(car.getOwner() == nullptr);
    REQUIRE(plane.getRegistration() == "PL8765KG");
    REQUIRE(plane.getDescription() == "Black plane");
    REQUIRE(plane.getOwner() == nullptr);
}

TEST_CASE("person getters")
{
    Person pesho("Peter Kolev", 1106);
    Person mirela("Mirela Nikolova", 1804);
    Person kate("Katerina Georgieva", 702);

    REQUIRE(pesho.getName() == "Peter Kolev");
    REQUIRE(pesho.getId() == 1106);
    REQUIRE(pesho.getNumberOfOwnedVehicles() == 0);
    REQUIRE(mirela.getName() == "Mirela Nikolova");
    REQUIRE(mirela.getId() == 1804);
    REQUIRE(pesho.getNumberOfOwnedVehicles() == 0);
    REQUIRE(kate.getName() == "Katerina Georgieva");
    REQUIRE(kate.getId() == 702);
    REQUIRE(pesho.getNumberOfOwnedVehicles() == 0);
}

TEST_CASE("acquire, release")
{
    Person pesho("Peter Kolev", 1106);
    Person mirela("Mirela Nikolova", 1804);
    Person kate("Katerina Georgieva", 702);

    Vehicle yacht("V3945PK", "White yacht");
    Vehicle car("PL1234MN", "Red car");
    Vehicle plane("PL8765KG", "Black plane");
    Vehicle bike("V3946PK", "Black bike");
    Vehicle bus("PL1111MN", "Yellow bus");
    Vehicle ship("V1106PK", "Grey ship");

    REQUIRE_NOTHROW(pesho.acquireNewVehicle(&yacht));
    REQUIRE_NOTHROW(pesho.acquireNewVehicle(&bike));
    REQUIRE_NOTHROW(pesho.acquireNewVehicle(&ship));
    REQUIRE_NOTHROW(mirela.acquireNewVehicle(&car));
    REQUIRE_NOTHROW(mirela.acquireNewVehicle(&bus));
    REQUIRE_NOTHROW(kate.acquireNewVehicle(&plane));

    REQUIRE(pesho.getNumberOfOwnedVehicles() == 3);
    REQUIRE(pesho.getVehicle(0) == &yacht);
    REQUIRE(pesho.getVehicle(1) == &bike);
    REQUIRE(pesho.getVehicle(2) == &ship);

    REQUIRE(mirela.getNumberOfOwnedVehicles() == 2);
    REQUIRE(mirela.getVehicle(0) == &car);
    REQUIRE(mirela.getVehicle(1) == &bus);

    REQUIRE(kate.getNumberOfOwnedVehicles() == 1);
    REQUIRE(kate.getVehicle(0) == &plane);

    REQUIRE_NOTHROW(yacht.addOwner(&pesho));
    REQUIRE_NOTHROW(bike.addOwner(&pesho));
    REQUIRE_NOTHROW(ship.addOwner(&pesho));
    REQUIRE_NOTHROW(car.addOwner(&mirela));
    REQUIRE_NOTHROW(bus.addOwner(&mirela));
    REQUIRE_NOTHROW(plane.addOwner(&kate));

    REQUIRE_NOTHROW(yacht.getOwner() == &pesho);
    REQUIRE_NOTHROW(bike.getOwner() == &pesho);
    REQUIRE_NOTHROW(ship.getOwner() == &pesho);

    REQUIRE_NOTHROW(car.getOwner() == &mirela);
    REQUIRE_NOTHROW(bus.getOwner() == &mirela);

    REQUIRE_NOTHROW(plane.getOwner() == &kate);

    SECTION ("release vehicles one by one")
    {
        REQUIRE_NOTHROW(pesho.releaseVehicle(&yacht));
        REQUIRE_NOTHROW(pesho.releaseVehicle(&bike));
        REQUIRE_NOTHROW(pesho.releaseVehicle(&ship));
        REQUIRE_NOTHROW(mirela.releaseVehicle(&car));
        REQUIRE_NOTHROW(mirela.releaseVehicle(&bus));
        REQUIRE_NOTHROW(kate.releaseVehicle(&plane));  

        REQUIRE(pesho.getNumberOfOwnedVehicles() == 0);
        REQUIRE(mirela.getNumberOfOwnedVehicles() == 0);
        REQUIRE(kate.getNumberOfOwnedVehicles() == 0);
    } 

    SECTION ("release all vehicles at once")
    {
        REQUIRE_NOTHROW(pesho.releaseAll());
        REQUIRE_NOTHROW(mirela.releaseAll());
        REQUIRE_NOTHROW(kate.releaseAll());

        REQUIRE(pesho.getNumberOfOwnedVehicles() == 0);
        REQUIRE(mirela.getNumberOfOwnedVehicles() == 0);
        REQUIRE(kate.getNumberOfOwnedVehicles() == 0);
    }

    REQUIRE_NOTHROW(yacht.removeOwner(&pesho));
    REQUIRE_NOTHROW(bike.removeOwner(&pesho));
    REQUIRE_NOTHROW(ship.removeOwner(&pesho));
    REQUIRE_NOTHROW(car.removeOwner(&mirela));
    REQUIRE_NOTHROW(bus.removeOwner(&mirela));
    REQUIRE_NOTHROW(plane.removeOwner(&kate));

    REQUIRE(yacht.getOwner() == nullptr);
    REQUIRE(bike.getOwner() == nullptr);
    REQUIRE(ship.getOwner() == nullptr);
    REQUIRE(car.getOwner() == nullptr);
    REQUIRE(bus.getOwner() == nullptr);
    REQUIRE(plane.getOwner() == nullptr);
}