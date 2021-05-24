#pragma once

#include <string>
#include <vector>
#include <cstddef>

class Vehicle;

#include "vehicle.h"

class Person
{
private:
    unsigned int id;
    std::string name;
    std::vector<Vehicle*> vehicles;

public:
    Person(std::string name, unsigned int id);

    unsigned int getId() const;
    std::string getName() const;
    std::size_t getNumberOfOwnedVehicles() const;
    Vehicle* getVehicle(std::size_t index) const; 

    void acquireNewVehicle(Vehicle* vehicle);
    void releaseVehicle(Vehicle* vehicle);
    void releaseAll();  

    bool operator == (const Person& other) const;
    friend std::ostream& operator << (std::ostream& out, const Person& person);
};

