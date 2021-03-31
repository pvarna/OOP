#pragma once

#include "person.h"
#include "enums.h"

class Car
{
private:
    Person owner;
    char* brand;
    char* licensePlate;
    Color color;

    void copy(const Car& other);
    void deallocate();

public:
    Car();
    Car(const Person& _owner, const char* _brand, const char* _licensePlate, const Color _color);
    Car(const Car& other);

    Car& operator = (const Car& other);

    Person getOwner() const;
    char* getBrand() const;
    char* getLicensePlate() const;
    Color getColor() const;

    void setOwner(const Person& _owner);
    void setBrand(const char* _brand);
    void setLicensePlate(const char* _licensePlate);
    void setColor(const Color _color);

    void print();

    ~Car();
};