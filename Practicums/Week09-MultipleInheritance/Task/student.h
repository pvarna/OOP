#pragma once

#include "person.h"

class Student : virtual public Person
{
protected:
    unsigned int number;

public:
    Student(std::string name, unsigned int number);

    unsigned int getNumber() const;
};