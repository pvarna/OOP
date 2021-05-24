#pragma once

#include "registration.h"
#include <string>

class Person;

#include "person.h"
class Vehicle
{
private:
    Registration registration;
    std::string description;
    Person* owner;

public:
    Vehicle(std::string registration, std::string description);

    std::string getRegistration() const;
    std::string getDescription() const;
    Person* getOwner() const;

    void addOwner(Person* person);
    void removeOwner(Person* person);

    bool operator == (const Vehicle& other) const;
    friend std::ostream& operator << (std::ostream& out, const Vehicle& other);
};