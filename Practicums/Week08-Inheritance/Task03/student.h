#pragma once

#include <string>
#include "human.h"

class Student : public Human
{
private:
    static unsigned int counter;
    unsigned int facultyNumber;
    std::string specialty;

public:
    Student(std::string name, std::string family, unsigned int age, std::string specialty);

    void print();
};