#include <iostream>
#include "Processor.h"

Processor::Processor(std::string name) : Component()
{
    this->name = name;
}

void Processor::print()
{
    std::cout << "Processor" << std::endl;
    Component::print();
    std::cout << "Name: " << this->name << std::endl;
}