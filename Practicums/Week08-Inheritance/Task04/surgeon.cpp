#include <iostream>
#include "surgeon.h"

Surgeon::Surgeon(std::string name) : Doctor(name) {}

void Surgeon::performSurgery()
{
    Doctor::performSurgery();
    std::cout << "Surgeon" << std::endl;
}