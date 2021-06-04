#include "bed.h"

Bed::Bed(double height, double width, double length, std::size_t quantity, double price)
    : Furniture(height, width, length, quantity, price)
{}

void Bed::print()
{
    Furniture::print();
}