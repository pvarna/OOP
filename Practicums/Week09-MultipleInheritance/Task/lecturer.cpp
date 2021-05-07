#include "lecturer.h"

Lecturer::Lecturer(std::string name, unsigned int salary) : Person(name)
{
    this->salary = salary;
}

unsigned int Lecturer::getSalary() const
{
    return this->salary;
}