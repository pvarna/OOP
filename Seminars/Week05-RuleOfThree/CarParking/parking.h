#pragma once

#include "person.h"
#include "car.h"

class Parking
{
private:
    char* nameCompany;
    Person owner;
    Car* cars;
    size_t size;
    size_t capacity;

    void copy(const Parking& other);
    void deallocate();
    void resize();

public:
    Parking();
    Parking(const char* _nameCompany, const Person _owner, const Car* _cars,
             const size_t _size, const size_t _capacity);
    Parking(const Parking& other);

    Parking& operator = (const Parking& other);

    char* getNameCompany() const;
    Person getOwner() const;
    Car* getCars() const;
    size_t getSize() const;
    size_t getCapacity() const;

    void setNameCompany(const char* _nameCompany);
    void setOwner(const Person& _owner);
    void setCars(const Car* _cars, const size_t _size);
    void setCapacity(const size_t _capacity);

    void addCar(const Car& car);
    void removeCar(const int index);

    void printAllCars();

    Person getOwnerByLicensePlate(const char* licensePlate);
    Car* getCarsByOwner(const char* name, size_t& count);

    ~Parking();
};
