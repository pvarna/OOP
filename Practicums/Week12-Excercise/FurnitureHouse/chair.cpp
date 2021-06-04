#include "chair.h"
#include <iostream>

Chair::Chair(double height, double width, double length, std::size_t quantity, double price, ChairType type)
    : Furniture(height, width, length, quantity, price)
{
    this->type = type;
}

void Chair::print()
{
    Furniture::print();
    
    std::cout << "Type: ";
    switch (this->type)
    {
    case ChairType::WOODEN:
        std::cout << "wooden" << std::endl;
        break;

    case ChairType::PLASTIC:
        std::cout << "plastic" << std::endl;
        break;

    case ChairType::METAL:
        std::cout << "metal" << std::endl;
        break;
    
    default:
        std::cout << "unknown" << std::endl;
        break;
    }
}