#pragma once

#include "furniture.h"

class Bed : public Furniture
{
public:
    Bed(double height, double width, double length, std::size_t quantity, double price);

    void print();
};