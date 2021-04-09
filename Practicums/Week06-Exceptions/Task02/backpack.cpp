#include <iostream>
#include "backpack.h"

void Backpack::copy(const Backpack& other)
{
    this->size = other.size;

    try
    {
        this->items = new Item[this->size];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < this->size; ++i)
    {
        this->items[i] = other.items[i];
    }

    this->maxVolume = other.maxVolume;
    this->maxWeight = other.maxWeight;    
}

void Backpack::deallocate()
{
    if (this->items)
    {
        delete[] this->items;
    }

    this->items = nullptr;
    this->size = 0;
    this->maxVolume = 0;
    this->maxWeight = 0;
}

Backpack::Backpack(double maxVolume, double maxWeight)
{
    this->items = nullptr;
    this->size = 0;
    this->maxVolume = maxVolume;
    this->maxWeight = maxWeight;
}

Backpack::Backpack(const Backpack& other)
{
    this->copy(other);
}

Backpack::~Backpack()
{
    this->deallocate();
}

Backpack& Backpack::operator = (const Backpack& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

void Backpack::add(const Item &item)
{
    try
    {
        if (item.getVolume() > this->maxVolume)
        {
            throw VolumeOverflow();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        if (item.getWeight() > this->maxWeight)
        {
            throw WeightOverflow();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Item* newItems;
    try
    {
        newItems = new Item[this->size + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    for (int i = 0; i < this->size; ++i)
    {
        newItems[i] = this->items[i];
    }
    if (this->items)
    {
        delete this->items;
    }

    this->items = newItems;
    this->items[this->size++] = item;
    this->maxVolume -= item.getVolume();
    this->maxWeight -= item.getWeight();
}

int Backpack::getSize() const
{
    return this->size;
}

double Backpack::leftVolume() const
{
    return this->maxVolume;
}

double Backpack::leftWeight() const
{
    return this->maxWeight;
}

Item& Backpack::operator [] (int index)
{
    try
    {
        if (index >= this->size)
        {
            throw std::out_of_range("Invalid index");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return this->items[index];    
}