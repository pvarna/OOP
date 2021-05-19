#pragma once

#include "food.h"
#include <string>

class Pizza: public Food
{
private:
    std::string type;

public:
    Pizza(std::string type, double weight, unsigned int pieces, double price);
};