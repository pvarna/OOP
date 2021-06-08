#include "park.h"
#include <iostream>

Park::Park(std::string name) : name(std::move(name))
{}

std::string Park::getName() const
{
    return this->name;
}

Park::~Park()
{
    std::cout << "Destroyed" << std::endl;
}