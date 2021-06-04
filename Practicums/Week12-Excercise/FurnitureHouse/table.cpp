#include "table.h"
#include <iostream>

Table::Table(double height, double width, double length, std::size_t quantity, double price, TableType type)
    : Furniture(height, width, length, quantity, price)
{
    this->type = type;
}

void Table::print()
{
    Furniture::print();
    
    std::cout << "Type: ";
    switch (this->type)
    {
    case TableType::LIVING_ROOM:
        std::cout << "living room table" << std::endl;
        break;

    case TableType::KITCHEN:
        std::cout << "kitchen table" << std::endl;
        break;
    
    default:
        std::cout << "unknown" << std::endl;
        break;
    }
}