#include <iostream>
#include <cstring>
#include "car.h"

void Car::setOwner(const Person& _owner)
{
    this->owner = _owner;
}

void Car::setBrand(const char* _brand)
{
    if (this->brand)
    {
        delete[] this->brand;
    }
    this->brand = new char[strlen(_brand) + 1];
    strcpy(this->brand, _brand);
}

void Car::setLicensePlate(const char* _licensePlate)
{
    if (this->licensePlate)
    {
        delete[] this->licensePlate;
    }
    this->licensePlate = new char[strlen(_licensePlate) + 1];
    strcpy(this->licensePlate, _licensePlate);
}

void Car::setColor(const Color& _color)
{
    this->color = _color;
}

void Car::copy(const Car& other)
{
    setOwner(other.owner);
    setBrand(other.brand);
    setLicensePlate(other.licensePlate);
    setColor(other.color);    
}

void Car::deallocate()
{
    if (this->brand)
    {
        delete[] this->brand;
    }
    if (this->licensePlate)
    {
        delete[] this->licensePlate;
    }
}

Car::Car() : owner()
{
    //this->owner();
    this->brand = nullptr;
    this->licensePlate = nullptr;
    this->color = UNKNOWN;
}

Car::Car(const Person _owner, const char* _brand, const char* _licensePlate, const Color _color)
{
    setOwner(_owner);
    setBrand(_brand);
    setLicensePlate(_licensePlate);
    setColor(_color);
}

Car::Car(const Car& other)
{
    copy(other);
}

Car::~Car()
{
    deallocate();
}

Car& Car::operator = (const Car& other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

Person Car::getOwner() const
{
    return this->owner;
}

char* Car::getBrand() const
{
    return this->brand;
}

char* Car::getLicensePlate() const
{
    return this->licensePlate;
}

Color Car::getColor() const
{
    return this->color;
}

void Car::print()
{
    std::cout << "Owner: " << std::endl;
    this->owner.print();
    std::cout << "Brand: " << this->brand << std::endl;
    std::cout << "License plate: " << this->licensePlate << std::endl;
    std::cout << "Color: ";
    switch (this->color)
    {
    case RED:
        std::cout << "red";
        break;
    case BLUE:
        std::cout << "blue";
        break;
    case BLACK:
        std::cout << "black";
        break;
    case WHITE:
        std::cout << "white";
        break;
    case GRAY:
        std::cout << "gray";
        break;
    case PURPLE:
        std::cout << "purple";
        break;
    case YELLOW:
        std::cout << "yellow";
        break;
    default:
        std::cout << "unknown";
        break;
    }
    std::cout << std::endl;
}
