#pragma once

class Item
{
private:
    char* name;
    double weight;
    double volume;

    void copy(const Item& other);
    void deallocate();
public:
    Item();
    Item(const char* name, const double weight, const double volume);
    Item(const Item& other);
    ~Item();

    Item& operator = (const Item& other);
    bool operator == (const Item& other) const;
    bool operator > (const Item& other) const;

    char* getName() const;
    double getWeight() const;
    double getVolume() const;
};