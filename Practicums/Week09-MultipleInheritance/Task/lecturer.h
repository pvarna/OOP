#pragma once

#include "person.h"

class Lecturer : virtual public Person
{
protected:
    unsigned int salary;

public:
    Lecturer(std::string name, unsigned int salary);

    unsigned int getSalary() const;
};