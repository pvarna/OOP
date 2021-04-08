#include <cstring>
#include <iostream>
#include "parking.h"

void Parking::copy(const Parking& other)
{
    this->nameCompany = new char[strlen(other.nameCompany) + 1];
    strcpy(this->nameCompany, other.nameCompany);

    this->owner = other.owner;
    this->capacity = other.capacity;
    this->size = other.size;

    this->cars = new Car[this->capacity];
    for (int i = 0; i < this->size; ++i)
    {
        this->cars[i] = other.cars[i];
    }
}

void Parking::deallocate()
{
    if (this->nameCompany)
    {
        delete[] this->nameCompany;
    }
    if (this->cars)
    {
        delete[] this->cars;
    }
}

void Parking::resize()
{
    this->capacity *= INCREASE_STEP;

    Car* newCars = new Car[this->capacity];
    
    for (int i = 0; i < this->size; ++i)
    {
        newCars[i] = this->cars[i];
    }
    delete[] this->cars;

    this->cars = newCars;
}

Parking::Parking() :owner()
{
    this->nameCompany = nullptr;
    this->capacity = INITIAL_CAPACITY;
    this->cars = new Car[this->capacity];
    this->size = 0;
}

Parking::Parking(const char* _nameCompany, const Person& _owner, const Car* _cars,
         const size_t _size, const size_t _capacity)
{
    this->nameCompany = new char[strlen(_nameCompany) + 1];
    strcpy(this->nameCompany, _nameCompany);

    this->owner = _owner;
    this->capacity = _capacity;
    this->size = _size;

    this->cars = new Car[this->capacity]
    ;
    for (int i = 0; i < this->size; ++i)
    {
        this->cars[i] = _cars[i];
    }
}

Parking::Parking(const Parking& other)
{
    copy(other);
}

Parking& Parking::operator = (const Parking& other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

char* Parking::getNameCompany() const
{
    return this->nameCompany;
}

Person Parking::getOwner() const
{
    return this->owner;
}

Car* Parking::getCars() const
{
    return this->cars;
}

size_t Parking::getSize() const
{
    return this->size;
}

size_t Parking::getCapacity() const
{
    return this->capacity;
}

void Parking::setNameCompany(const char* _nameCompany)
{
    if (this->nameCompany)
    {
        delete[] this->nameCompany;
    }
    this->nameCompany = new char[strlen(_nameCompany) + 1];
    strcpy(this->nameCompany, _nameCompany);
}

void Parking::setOwner(const Person& _owner)
{
    this->owner = _owner;
}

void Parking::setCars(const Car* _cars, const size_t _size)
{
    if (this->cars)
    {
        delete[] this->cars;
    }

    this->cars = (_size > this->capacity) ? (new Car[_size]) : (new Car[this->capacity]);
    for (int i = 0; i < _size; ++i)
    {
        this->cars[i] = _cars[i];
    }
}

void Parking::setCapacity(const size_t _capacity)
{
    this->capacity = _capacity;
}

void Parking::addCar(const Car& car)
{
    if (this->size == this->capacity)
    {
        resize();
    }

    for (int i = 0; i < this->size; ++i)
    {
        if (strcmp(cars[i].getLicensePlate(), car.getLicensePlate()) == 0)
        {
            std::cout << "There is already a car with this license plate in the parking" << std::endl;
        }
    }

    this->cars[this->size++] = car;
}

void Parking::removeCar(const int index)
{
    if (index >= this->size)
    {
        std::cout << "There is no car with such index" << std::endl;
        return;
    }

    for (int i = index; i < this->size - 1; ++i)
    {
        this->cars[i] = this->cars[i+1];
    }

    --this->size;
}

void Parking::printAllCars()
{
    std::cout << "Size: " << this->size << std::endl;
    std::cout << "Capacity: " << this->capacity << std::endl;
    std::cout << ((double)this->size/(double)this->capacity)*100 << "% full" << std::endl;
    for (int i = 0; i < this->size; ++i)
    {
        std::cout << "Car #" << i+1 << ":" << std::endl;
        cars[i].print();
    }
}

Person Parking::getOwnerByLicensePlate(const char* licensePlate)
{
    Person result;
    for (int i = 0; i < this->size; ++i)
    {
        if (strcmp(licensePlate, cars[i].getLicensePlate()) == 0)
        {
            result = cars[i].getOwner();
        }
    }

    return result;
}

Car* Parking::getCarsByOwner(const Person& owner, size_t& count)
{
    count = 0;
    for (int i = 0; i < this->size; ++i)
    {
        if (cars[i].getOwner() == owner)
        {
            ++count;
        }
    }

    if (count == 0)
    {
        std::cout << "No cars found" << std::endl;
        return nullptr;
    }

    Car* result = new Car[count];
    int index = 0;
    for (int i = 0; i < this->size; ++i)
    {
        if (cars[i].getOwner() == owner)
        {
            result[index++] = cars[i];
        }
    }

    return result;
}

Parking::~Parking()
{
    deallocate();
}