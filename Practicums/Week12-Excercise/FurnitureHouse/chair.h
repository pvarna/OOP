#pragma once

#include "furniture.h"

enum class ChairType
{
    UNKNOWN = -1,
    WOODEN,
    PLASTIC,
    METAL
};

class Chair : public Furniture
{
private:
    ChairType type;

public:
    Chair(double height, double width, double length, std::size_t quantity, double price, ChairType type);

    void print();
};