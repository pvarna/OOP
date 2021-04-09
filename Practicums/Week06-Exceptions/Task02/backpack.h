#pragma once

#include "item.h"
#include "exceptions.h"

class Backpack
{
private:
    Item* items;
    int size;
    double maxVolume;
    double maxWeight;

    void copy(const Backpack& other);
    void deallocate();

public:
    Backpack(double maxVolume = 0.0, double maxWeight = 0.0);
    Backpack(const Backpack& other);
    ~Backpack();

    Backpack& operator = (const Backpack& other);
    void add(const Item &item);
    Item& operator [] (int index);

    int getSize() const;
    double leftVolume() const;
    double leftWeight() const;
};
