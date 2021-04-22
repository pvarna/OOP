#include <iostream>
#include "RAM.h"

RAM::RAM(std::string name) : Component()
{
    this->name = name;
}

void RAM::print()
{
    std::cout << "RAM" << std::endl;
    Component::print();
    std::cout << "Name: " << this->name << std::endl;
}