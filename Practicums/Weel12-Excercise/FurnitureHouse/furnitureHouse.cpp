#include "furnitureHouse.h"
#include <iostream>

FurnitureHouse::FurnitureHouse()
{}

FurnitureHouse::~FurnitureHouse()
{
    std::size_t size = this->furniture.size();
    for (std::size_t i = 0; i < size; ++i)
    {
        delete this->furniture[i];
    }
}

void FurnitureHouse::addNewFurniture(Furniture* furniture)
{
    std::size_t size = this->furniture.size();

    for (std::size_t i = 0; i < size; ++i)
    {
        if (this->furniture[i]->getId() == furniture->getId())
        {
            this->furniture[i]->increaseQuantityBy(furniture->getQuantity());
            return;
        }
    }

    this->furniture.push_back(furniture);
}

void FurnitureHouse::removeFurniture(unsigned int id)
{
    std::size_t size = this->furniture.size();

    for (std::size_t i = 0; i < size; ++i)
    {
        if (this->furniture[i]->getId() == id)
        {
            if (this->furniture[i]->getQuantity() > 1)
            {
                this->furniture[i]->reduceQuantityBy(1);
            }
            else
            {
                this->furniture.erase(this->furniture.begin() + i);
            }
            return;
        }
    }

    throw std::invalid_argument("There is not such id");
}

void FurnitureHouse::showInfo(unsigned int id)
{
    std::size_t size = this->furniture.size();

    for (std::size_t i = 0; i < size; ++i)
    {
        if (this->furniture[i]->getId() == id)
        {
            this->furniture[i]->print();
            return;
        }
    }

    throw std::invalid_argument("There is not such id");
}