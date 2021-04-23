#include <iostream>
#include "dentist.h"

Dentist::Dentist(std::string name) : Doctor(name) {}

void Dentist::performSurgery()
{
    Doctor::performSurgery();
    std::cout << "Dentist" << std::endl;
}