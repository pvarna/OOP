#include <iostream>
#include "HardDrive.h"

HardDrive::HardDrive(std::string name) : Component()
{
    this->name = name;
}

void HardDrive::print()
{
    std::cout << "Hard Drive" << std::endl;
    Component::print();
    std::cout << "Name: " << this->name << std::endl;
}