#include "pizza.h"

Pizza::Pizza(std::string type, double weight, unsigned int pieces, double price)
    : Food(weight, pieces, price), type(type)
{}