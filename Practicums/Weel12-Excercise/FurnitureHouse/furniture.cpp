#include "furniture.h"
#include <iostream>

unsigned int Furniture::counter = 100;

Furniture::Furniture(double height, double width, double length, std::size_t quantity, double price)
{
    this->id = Furniture::counter++;
    this->height = height;
    this->width = width;
    this->length = length;
    this->quantity = quantity;
    this->price = price;
}

unsigned int Furniture::getId() const
{
    return this->id;
}

std::size_t Furniture::getQuantity() const
{
    return this->quantity;
}

void Furniture::increaseQuantityBy(unsigned int by)
{
    this->quantity += by;
}

void Furniture::reduceQuantityBy(unsigned int by)
{
    this->quantity -= by;
}

void Furniture::print()
{
    std::cout << "Id: " << this->id << std::endl;
    std::cout << "Height: " << this->height << std::endl;
    std::cout << "Width: " << this->width << std::endl;
    std::cout << "Length: " << this->length << std::endl;
    std::cout << "Quantity: " << this->quantity << std::endl;
    std::cout << "Price: " << this->price << std::endl;
}