#include "../Headers/person.h"
#include <stdexcept>
#include <iostream>

Person::Person(std::string name, unsigned int id)
{
    this->name = name;
    this->id = id;
}

std::size_t Person::getNumberOfOwnedVehicles() const
{
    return this->vehicles.size();
}

unsigned int Person::getId() const
{
    return this->id;
}

std::string Person::getName() const
{
    return this->name;
}

Vehicle* Person::getVehicle(std::size_t index) const
{
    std::size_t numberOwnedVehicles = this->vehicles.size();
    if (index >= numberOwnedVehicles)
    {
        throw std::invalid_argument("Invalid index!");
    }

    return this->vehicles[index];
}

bool Person::operator == (const Person& other) const
{
    return this->id == other.id && this->name == other.name;
}

void Person::acquireNewVehicle(Vehicle* vehicle)
{
    Person* owner = vehicle->getOwner();
    if (owner)
    {
        vehicle->removeOwner(owner);
        owner->releaseVehicle(vehicle);
    }

    this->vehicles.push_back(vehicle);
}

void Person::releaseVehicle(Vehicle* vehicle)
{
    std::size_t numberOwnedVehicles = this->vehicles.size();

    if (numberOwnedVehicles == 0)
    {
        throw std::invalid_argument("This person does not own any vehicles!");
    }

    int searchedIndex = -1;
    for (std::size_t i = 0; i < numberOwnedVehicles; ++i)
    {
        if (this->vehicles[i] == vehicle)
        {
            searchedIndex = i;
            break;
        }
    }

    if (searchedIndex == -1)
    {
        throw std::invalid_argument("This person does not own vehicle with such registration!");
    }

    this->vehicles[searchedIndex] = nullptr;
    this->vehicles.erase(this->vehicles.begin() + searchedIndex);
}

void Person::releaseAll()
{
    std::size_t numberOwnedVehicles = this->vehicles.size();
    for (std::size_t i = 0; i < numberOwnedVehicles; ++i)
    {
        this->vehicles[i] = nullptr;       
    }

    this->vehicles.clear();
}

std::ostream& operator << (std::ostream& out, const Person& person)
{
    out << "Id: " << person.getId() << std::endl;
    out << "Name: " << person.getName() << std::endl;

    std::size_t numberOwnedVehicles = person.getNumberOfOwnedVehicles();
    if (numberOwnedVehicles > 0)
    {
        out << "Vehicles:" << std::endl;
        for (std::size_t i = 0; i < numberOwnedVehicles; ++i)
        {
            out << person.vehicles[i]->getRegistration();
            if (i != numberOwnedVehicles - 1)
            {
                std::cout << std::endl;
            }
        }
    }
    else
    {
        out << "No vehicles";
    }

    return out;
}