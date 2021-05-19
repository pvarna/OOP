#pragma once

#include "food.h"
#include <iostream>

class Salad : public Food
{
private:
    unsigned int countOfIngredients;
    bool isSpiced;

public:
    Salad(unsigned int countOfIngredients, bool isSpiced, double weight, double price);
};