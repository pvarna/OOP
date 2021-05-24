#pragma once

#include "vehicle.h"
#include "person.h"
#include <vector>

class Data
{
private:
    std::vector<Vehicle*> vehicles;
    std::vector<Person*> people;

    bool isNumber(std::string string);
    bool fileExists(std::string fileName);

public:
    Data();
    Data(const Data& other) = delete;
    Data& operator = (const Data& other) = delete;
    ~Data();

    std::size_t getNumberOfVehicles() const;
    std::size_t getNumberOfPeople() const;

    Vehicle* getVehicle(std::size_t index);
    Person* getPerson(std::size_t index);

    void addNewVehicle(std::string registration, std::string description);
    void addNewPerson(std::string name, std::string id);
    void acquire(std::string ownerId, std::string vehicleId);
    void release(std::string ownerId, std::string vehicleId);
    void remove(std::string what);
    void show(std::string what);
    void saveIntoFile(std::string fileName);
};