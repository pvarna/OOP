#pragma once

#include <string>
#include "Component.h"

class RAM : public Component
{
private:
    std::string name;

public:
    RAM(std::string name);

    void print();
};