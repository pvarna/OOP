#pragma once

#include "furniture.h"

enum class TableType
{
    UNKNOWN = -1,
    LIVING_ROOM,
    KITCHEN
};

class Table : public Furniture
{
private:
    TableType type;

public:
    Table(double height, double width, double length, std::size_t quantity, double price, TableType type);

    void print();
};