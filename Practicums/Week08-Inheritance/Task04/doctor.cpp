#include <iostream>
#include "doctor.h"

Doctor::Doctor(std::string name)
{
    this->name = name;
}

void Doctor::performSurgery()
{
    std::cout << "Surgery performermed by " << this->name << std::endl;
}