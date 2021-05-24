//#define CATCH_CONFIG_MAIN
#include "../catch2/catch2.hpp"
#include "../Headers/data.h"

TEST_CASE("adding vehicles")
{
    Data data;

    REQUIRE_NOTHROW(data.addNewVehicle("V3947PK", "Grey Mercedes"));
    REQUIRE_NOTHROW(data.addNewVehicle("V3945PK", "Black BMW"));
    REQUIRE_NOTHROW(data.addNewVehicle("SA3946PK", "White Audi"));

    REQUIRE(data.getNumberOfVehicles() == 3);
    REQUIRE(data.getNumberOfPeople() == 0);

    SECTION("invalid registrations")
    {
        REQUIRE_THROWS(data.addNewVehicle("ejwfhje", "klkehher"));
        REQUIRE_THROWS(data.addNewVehicle("VVV35789", "klkehher"));
        REQUIRE_THROWS(data.addNewVehicle("1234567", "klkehher"));
    }

    SECTION("already created vehicles with these registrations")
    {
        REQUIRE_THROWS(data.addNewVehicle("V3947PK", "klkehher"));
        REQUIRE_THROWS(data.addNewVehicle("SA3946PK", "klkehher"));
    }

    REQUIRE(data.getNumberOfVehicles() == 3);
    REQUIRE(data.getNumberOfPeople() == 0);
}

TEST_CASE("adding people")
{
    Data data;

    REQUIRE_NOTHROW(data.addNewPerson("Peter Kolev", "3945"));
    REQUIRE_NOTHROW(data.addNewPerson("Sonya Nikolova", "1027"));
    REQUIRE_NOTHROW(data.addNewPerson("Georgi Ivanov", "5060"));

    REQUIRE(data.getNumberOfVehicles() == 0);
    REQUIRE(data.getNumberOfPeople() == 3);

    SECTION("already created vehicles with these ids")
    {
        REQUIRE_THROWS(data.addNewPerson("alabala", "3945"));
        REQUIRE_THROWS(data.addNewPerson("sajfhjffwe", "5060"));
    }

    REQUIRE(data.getNumberOfVehicles() == 0);
    REQUIRE(data.getNumberOfPeople() == 3);
}

TEST_CASE("acquire and release")
{
    Data data;

    REQUIRE_NOTHROW(data.addNewVehicle("V3945PK", "White yacht"));
    REQUIRE_NOTHROW(data.addNewVehicle("PL3946MN", "Red Toyota Rav4"));
    REQUIRE_NOTHROW(data.addNewVehicle("PL3947KG", "Black BMW"));
    REQUIRE_NOTHROW(data.addNewVehicle("SF1212PK", "White plane"));
    REQUIRE_NOTHROW(data.addNewVehicle("SF3333MN", "Red Lamborghini"));
    REQUIRE_NOTHROW(data.addNewVehicle("SF1234PK", "Black Porsche"));

    REQUIRE_NOTHROW(data.addNewPerson("Peter Kolev", "1106"));
    REQUIRE_NOTHROW(data.addNewPerson("Mirela Nikolova", "1804"));
    REQUIRE_NOTHROW(data.addNewPerson("Katerina Georgieva", "702"));

    SECTION("owner's id with letters")
    {
        REQUIRE_THROWS(data.acquire("1106PK", "V3945PK"));
    }

    SECTION("ids of non-existent people")
    {
        REQUIRE_THROWS(data.acquire("1206", "V3945PK"));
    }

    SECTION("registrations of non-existent vehicles")
    {
        REQUIRE_THROWS(data.acquire("1106", "V3944PK"));
    }

    REQUIRE_NOTHROW(data.acquire("1106", "V3945PK"));
    REQUIRE_NOTHROW(data.acquire("1106", "SF1212PK"));
    REQUIRE_NOTHROW(data.acquire("1106", "SF1234PK"));
    REQUIRE_NOTHROW(data.acquire("1804", "PL3946MN"));
    REQUIRE_NOTHROW(data.acquire("1804", "SF3333MN"));
    REQUIRE_NOTHROW(data.acquire("702", "PL3947KG"));

    REQUIRE(data.getNumberOfPeople() == 3);
    REQUIRE(data.getNumberOfVehicles() == 6);

    REQUIRE(data.getVehicle(0)->getOwner() == data.getPerson(0));
    REQUIRE(data.getVehicle(1)->getOwner() == data.getPerson(1));
    REQUIRE(data.getVehicle(2)->getOwner() == data.getPerson(2));
    REQUIRE(data.getVehicle(3)->getOwner() == data.getPerson(0));
    REQUIRE(data.getVehicle(4)->getOwner() == data.getPerson(1));
    REQUIRE(data.getVehicle(5)->getOwner() == data.getPerson(0));

    REQUIRE(data.getPerson(0)->getVehicle(0) == data.getVehicle(0));
    REQUIRE(data.getPerson(0)->getVehicle(1) == data.getVehicle(3));
    REQUIRE(data.getPerson(0)->getVehicle(2) == data.getVehicle(5));
    REQUIRE(data.getPerson(1)->getVehicle(0) == data.getVehicle(1));
    REQUIRE(data.getPerson(1)->getVehicle(1) == data.getVehicle(4));
    REQUIRE(data.getPerson(2)->getVehicle(0) == data.getVehicle(2));

    REQUIRE(data.getPerson(0)->getNumberOfOwnedVehicles() == 3);
    REQUIRE(data.getPerson(1)->getNumberOfOwnedVehicles() == 2);
    REQUIRE(data.getPerson(2)->getNumberOfOwnedVehicles() == 1);

    REQUIRE_NOTHROW(data.acquire("1106", "PL3947KG"));

    REQUIRE(data.getVehicle(0)->getOwner() == data.getPerson(0));
    REQUIRE(data.getVehicle(1)->getOwner() == data.getPerson(1));
    REQUIRE(data.getVehicle(2)->getOwner() == data.getPerson(0));
    REQUIRE(data.getVehicle(3)->getOwner() == data.getPerson(0));
    REQUIRE(data.getVehicle(4)->getOwner() == data.getPerson(1));
    REQUIRE(data.getVehicle(5)->getOwner() == data.getPerson(0));

    REQUIRE(data.getPerson(0)->getVehicle(0) == data.getVehicle(0));
    REQUIRE(data.getPerson(0)->getVehicle(1) == data.getVehicle(3));
    REQUIRE(data.getPerson(0)->getVehicle(2) == data.getVehicle(5));
    REQUIRE(data.getPerson(1)->getVehicle(0) == data.getVehicle(1));
    REQUIRE(data.getPerson(1)->getVehicle(1) == data.getVehicle(4));
    REQUIRE(data.getPerson(0)->getVehicle(3) == data.getVehicle(2));

    REQUIRE(data.getPerson(0)->getNumberOfOwnedVehicles() == 4);
    REQUIRE(data.getPerson(1)->getNumberOfOwnedVehicles() == 2);
    REQUIRE(data.getPerson(2)->getNumberOfOwnedVehicles() == 0);

    REQUIRE_NOTHROW(data.addNewPerson("Kaloyan Sokolov", "1205"));
    REQUIRE_NOTHROW(data.addNewVehicle("SF1205KS", "Red KIA"));

    SECTION("trying to release a vehicle without an owner")
    {
        REQUIRE_THROWS(data.release("1106","SF1205KS"));
    }

    SECTION("trying to release from an owner withour vehicles")
    {
        REQUIRE_THROWS(data.release("1205", "V3945PK"));
    }

    SECTION("trying to release a vehicle which belongs to another person")
    {
        REQUIRE_THROWS(data.release("1106", "SF3333MN"));
    }

    SECTION("ids of non-existent people")
    {
        REQUIRE_THROWS(data.release("1206", "V3945PK"));
    }

    SECTION("registrations of non-existent vehicles")
    {
        REQUIRE_THROWS(data.release("1106", "V3944PK"));
    }

    REQUIRE_NOTHROW(data.release("1106", "V3945PK"));
    REQUIRE(data.getPerson(0)->getNumberOfOwnedVehicles() == 3);
    REQUIRE(data.getVehicle(0)->getOwner() == nullptr);

    REQUIRE_NOTHROW(data.release("1804", "PL3946MN"));
    REQUIRE(data.getPerson(1)->getNumberOfOwnedVehicles() == 1);
    REQUIRE(data.getVehicle(1)->getOwner() == nullptr);
    
    REQUIRE_NOTHROW(data.release("1106", "PL3947KG"));
    REQUIRE(data.getPerson(0)->getNumberOfOwnedVehicles() == 2);
    REQUIRE(data.getVehicle(2)->getOwner() == nullptr);

    REQUIRE_NOTHROW(data.release("1106", "SF1212PK"));
    REQUIRE(data.getPerson(0)->getNumberOfOwnedVehicles() == 1);
    REQUIRE(data.getVehicle(3)->getOwner() == nullptr);

    REQUIRE_NOTHROW(data.release("1804", "SF3333MN"));
    REQUIRE(data.getPerson(1)->getNumberOfOwnedVehicles() == 0);
    REQUIRE(data.getVehicle(4)->getOwner() == nullptr);

    REQUIRE_NOTHROW(data.release("1106", "SF1234PK"));
    REQUIRE(data.getPerson(0)->getNumberOfOwnedVehicles() == 0);
    REQUIRE(data.getVehicle(5)->getOwner() == nullptr);
}

TEST_CASE("remove")
{
    Data data;

    REQUIRE_NOTHROW(data.addNewVehicle("V3945PK", "White yacht"));
    REQUIRE_NOTHROW(data.addNewVehicle("PL3946MN", "Red Toyota Rav4"));
    REQUIRE_NOTHROW(data.addNewVehicle("PL3947KG", "Black BMW"));
    REQUIRE_NOTHROW(data.addNewVehicle("SF1212PK", "White plane"));
    REQUIRE_NOTHROW(data.addNewVehicle("SF3333MN", "Red Lamborghini"));
    REQUIRE_NOTHROW(data.addNewVehicle("SF1234PK", "Black Porsche"));

    REQUIRE_NOTHROW(data.addNewPerson("Peter Kolev", "1106"));
    REQUIRE_NOTHROW(data.addNewPerson("Mirela Nikolova", "1804"));
    REQUIRE_NOTHROW(data.addNewPerson("Katerina Georgieva", "702"));

    REQUIRE(data.getNumberOfPeople() == 3);
    REQUIRE(data.getNumberOfVehicles() == 6);

    REQUIRE_NOTHROW(data.acquire("1106", "V3945PK"));
    REQUIRE_NOTHROW(data.acquire("1106", "SF1212PK"));
    REQUIRE_NOTHROW(data.acquire("1106", "SF1234PK"));
    REQUIRE_NOTHROW(data.acquire("1804", "PL3946MN"));
    REQUIRE_NOTHROW(data.acquire("1804", "SF3333MN"));
    REQUIRE_NOTHROW(data.acquire("702", "PL3947KG"));

    SECTION("removing all vehicles")
    {
        REQUIRE_NOTHROW(data.remove("V3945PK"));
        REQUIRE(data.getNumberOfVehicles() == 5);
        REQUIRE(data.getPerson(0)->getNumberOfOwnedVehicles() == 2);

        REQUIRE_NOTHROW(data.remove("PL3946MN"));
        REQUIRE(data.getNumberOfVehicles() == 4);
        REQUIRE(data.getPerson(1)->getNumberOfOwnedVehicles() == 1);

        REQUIRE_NOTHROW(data.remove("PL3947KG"));
        REQUIRE(data.getNumberOfVehicles() == 3);
        REQUIRE(data.getPerson(2)->getNumberOfOwnedVehicles() == 0);

        REQUIRE_NOTHROW(data.remove("SF1212PK"));
        REQUIRE(data.getNumberOfVehicles() == 2);
        REQUIRE(data.getPerson(0)->getNumberOfOwnedVehicles() == 1);

        REQUIRE_NOTHROW(data.remove("SF3333MN"));
        REQUIRE(data.getNumberOfVehicles() == 1);
        REQUIRE(data.getPerson(1)->getNumberOfOwnedVehicles() == 0);

        REQUIRE_NOTHROW(data.remove("SF1234PK"));
        REQUIRE(data.getNumberOfVehicles() == 0);
        REQUIRE(data.getPerson(0)->getNumberOfOwnedVehicles() == 0);

        REQUIRE(data.getNumberOfPeople() == 3);
    }

    SECTION("removing all people")
    {
        REQUIRE_NOTHROW(data.remove("1106"));
        REQUIRE(data.getNumberOfPeople() == 2);
        REQUIRE(data.getVehicle(0)->getOwner() == nullptr);
        REQUIRE(data.getVehicle(3)->getOwner() == nullptr);
        REQUIRE(data.getVehicle(5)->getOwner() == nullptr);

        REQUIRE_NOTHROW(data.remove("1804"));
        REQUIRE(data.getNumberOfPeople() == 1);
        REQUIRE(data.getVehicle(1)->getOwner() == nullptr);
        REQUIRE(data.getVehicle(4)->getOwner() == nullptr);

        REQUIRE_NOTHROW(data.remove("702"));
        REQUIRE(data.getNumberOfPeople() == 0);
        REQUIRE(data.getVehicle(2)->getOwner() == nullptr);

        REQUIRE(data.getNumberOfVehicles() == 6);
    }
}