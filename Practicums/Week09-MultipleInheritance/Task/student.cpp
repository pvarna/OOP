#include "student.h"

Student::Student(std::string name, unsigned int number) : Person(name)
{
    this->number = number;
}

unsigned int Student::getNumber() const
{
    return this->number;
}