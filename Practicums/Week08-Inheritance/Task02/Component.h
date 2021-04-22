#pragma once

#include <string>
#include "ComponentSerialNumberGenerator.h"

/*
Processor
RAM
*/
class Component
{
protected:
    int serialNumber;
    
public:
    Component();
    void print();
};