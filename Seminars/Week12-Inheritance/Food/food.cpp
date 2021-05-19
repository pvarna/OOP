#include "food.h"
#include <iostream>

unsigned int Food::counter = 0;

Food::Food(double weight, unsigned int pieces, double price)
{
    this->weight = weight;
    this->pieces = pieces;
    this->weightPerPiece = weight/pieces;
    this->price = price;
    this->id = Food::counter++;
}

void Food::consume()
{
    if (this->pieces == 0)
    {
        std::underflow_error("No food left!");
    }

    --this->pieces;
    this->weight -= (this->weightPerPiece);
}

void Food::print()
{
    std::cout << "Id: " << this->id << std::endl;
    std::cout << "Weight: " << this->weight << std::endl;
    std::cout << "Pieces: " << this->pieces << std::endl;
    std::cout << "Weight per piece: " << this->weightPerPiece << std::endl;
    std::cout << "Price: " << this->price << std::endl;
}

unsigned int Food::getId()
{
    return this->id;
}

double Food::getPrice()
{
    return this->price;
}