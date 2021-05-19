#include "salad.h"

Salad::Salad(unsigned int countOfIngredients, bool isSpiced, double weight, double price)
    : Food(weight, 1, price)
{
    this->isSpiced = isSpiced;
    this->countOfIngredients = countOfIngredients;
}