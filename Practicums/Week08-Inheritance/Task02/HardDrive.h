#pragma once

#include <string>
#include "Component.h"

class HardDrive : public Component
{
private:
    std::string name;

public:
    HardDrive(std::string name);

    void print();
};