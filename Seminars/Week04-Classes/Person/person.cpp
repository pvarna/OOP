#include <iostream>
#include <cstring>
#include "person.h"

Person::Person()
{
    this->name = nullptr;
    this->age = 0;
    this->hasDriveLicense = false;
}

Person::~Person()
{
    delete[] this->name;
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
    this->name = new char[strlen(person.name) + 1];
    strcpy(this->name, person.name);

    this->age = person.age;
    this->hasDriveLicense = person.hasDriveLicense;
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

Person& Person::operator = (const Person& person)
{
    this->setName(person.name);
    this->setAge(person.age);
    this->setHasDriveLicense(person.hasDriveLicense);
    return *this;
}

std::ostream& operator << (std::ostream &out, const Person& person)
{
    out << "Name: ";
    out << (person.name ?  person.name : "N/A")  << std::endl;
    out << "Age: " << person.age << std::endl;
    out << "Has driving license: ";
    out << ((person.hasDriveLicense) ? "yes" : "no") << std::endl;

    return out;
}

std::istream& operator >> (std::istream& in, Person& person)
{
    char buffer[100];
    std::cout << "Please enter the name of the person: ";
    in >> buffer;
    delete[] person.name;
    person.name = new char[strlen(buffer) + 1];
    strcpy(person.name, buffer);

    std::cout << "Please enter the age of the person: ";
    in >> person.age;

    std::cout << "Does the person have a driving license? [y/n]: ";
    char ch;
    in >> ch;
    person.hasDriveLicense = (tolower(ch) == 'y'); 

    return in;
}