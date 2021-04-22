#include <iostream>
#include "Component.h"

Component::Component()
{
    this->serialNumber = ComponentSerialNumberGenerator::generateSerialNumber();
}

void Component::print()
{
    std::cout << "Serial number: " << this->serialNumber << std::endl;
}