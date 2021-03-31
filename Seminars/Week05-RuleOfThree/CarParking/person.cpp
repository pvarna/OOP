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
    deallocate();
}

Person::Person(const char* _name, const int _age, const bool _hasDriveLicense)
{
    this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);

    this->age = _age;
    this->hasDriveLicense = _hasDriveLicense;
}

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

Person::Person(const Person& person)
{
    copy(person);
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

Person& Person::operator = (const Person& other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }
    return *this;
}

/*std::ostream& operator << (std::ostream &out, const Person& person)
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
}*/