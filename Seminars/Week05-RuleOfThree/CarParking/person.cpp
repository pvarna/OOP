#include <iostream>
#include <cstring>
#include "person.h"

void Person::copy(const Person& other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);

    this->age = other.age;
    this->hasDriveLicense = other.hasDriveLicense;
}

void Person::deallocate()
{
    if (this->name)
    {
        delete[] this->name;
    }
}

Person::Person()
{
    this->name = nullptr;
    this->age = 0;
    this->hasDriveLicense = false;
}

Person::Person(const char* _name, const int _age, const bool _hasDriveLicense)
{
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);

    this->age = _age;
    this->hasDriveLicense = _hasDriveLicense;
}

Person::Person(const Person& person)
{
    copy(person);
}

Person& Person::operator = (const Person& other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }
    return *this;
}

char* Person::getName() const
{
    return this->name;
}

int Person::getAge() const
{
    return this->age;
}

bool Person::getHasDriveLicense() const
{
    return this->hasDriveLicense;
}

void Person::setName(const char* _name)
{
    delete[] this->name;
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

void Person::setAge(const int _age)
{
    this->age = _age;
}

void Person::setHasDriveLicense(const bool _hasDriveLicense)
{
    this->hasDriveLicense = _hasDriveLicense;
}

void Person::print()
{
    std::cout << "Name: ";
    std::cout << (name ?  this->name : "N/A")  << std::endl;
    std::cout << "Age: " << this->age << std::endl;
    std::cout << "Has driving license: ";
    std::cout << ((this->hasDriveLicense) ? "yes" : "no") << std::endl;
}

Person::~Person()
{
    deallocate();
}

bool Person::operator == (const Person& other) const
{
    if (!this->name || !other.name)
    {
        return this->name == other.name;
    }

    return strcmp(this->name, other.name) == 0 && this->age == other.age && 
           this->hasDriveLicense == other.hasDriveLicense;
}