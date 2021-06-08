#include "park.h"

Park::Park(std::string name) : name(std::move(name))
{}

std::string Park::getName() const
{
    return this->name;
}