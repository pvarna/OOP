#pragma once

#include <string>
#include "Component.h"

class Processor : public Component
{
private:
    std::string name;

public:
    Processor(std::string name);

    void print();
};