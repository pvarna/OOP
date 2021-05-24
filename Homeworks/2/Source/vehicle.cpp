#include "../Headers/vehicle.h"
#include <stdexcept>
#include <iostream>

Vehicle::Vehicle(std::string registration, std::string description) : registration(registration.c_str())
{
    this->description = description;
    this->owner = nullptr;
}

std::string Vehicle::getRegistration() const
{
    return this->registration.getRegistration();
}

std::string Vehicle::getDescription() const
{
    return this->description;
}

Person* Vehicle::getOwner() const
{
    return this->owner;
}

bool Vehicle::operator == (const Vehicle& other) const
{
    return this->registration == other.registration && this->description == other.description;
}

void Vehicle::addOwner(Person* person)
{
    if (this->owner)
    {
        throw std::invalid_argument("The vehicle is already owned by someone!");
    }

    this->owner = person;
}

void Vehicle::removeOwner(Person* person)
{
    if (!this->owner)
    {
        throw std::invalid_argument("This vehicle is not owned by anyone!");
    }

    if (person != this->owner)
    {
        throw std::invalid_argument("This vehicle is not owned by that owner!");
    }

    this->owner = nullptr;
}

std::ostream& operator << (std::ostream& out, const Vehicle& other)
{
    out << "Registration: " << other.registration.getRegistration() << std::endl;
    out << "Description: " << other.description << std::endl;
    if (other.owner)
    {
        out << "Owner: " << other.owner->getName();
    }
    else
    {
        out << "No owner";
    }

    return out;
}