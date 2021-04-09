#include <iostream>
#include <cstring>
#include "item.h"

void Item::copy(const Item& other)
{
    try
    {
        this->name = new char[strlen(other.name) + 1];    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->name, other.name);

    this->weight = other.weight;
    this->volume = other.volume;
}

void Item::deallocate()
{
    if (this->name)
    {
        delete[] this->name;
    }

    this->name = nullptr;
    this->volume = 0;
    this->weight = 0;
}

Item::Item()
{
    this->name = nullptr;
    this->volume = 0;
    this->weight = 0;
}

Item::Item(const char* name, const double weight, const double volume)
{
    try
    {
        this->name = new char[strlen(name) + 1];    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    strcpy(this->name, name);

    this->weight = weight;
    this->volume = volume;
}

Item::Item(const Item& other)
{
    this->copy(other);
}

Item::~Item()
{
    this->deallocate();
}

Item& Item::operator = (const Item& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

bool Item::operator == (const Item& other) const
{
    return strcmp(this->name, other.name) == 0 && this->weight == other.weight && 
            this->volume == other.volume;
}
bool Item::operator > (const Item& other) const
{
    return (this->volume > other.volume) || (this->volume == other.volume && this->weight > other.weight);
}

char* Item::getName() const
{
    return this->name;
}

double Item::getWeight() const
{
    return this->weight;
}

double Item::getVolume() const
{
    return this->volume;
}