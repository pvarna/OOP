#include "menu.h"
#include <iostream>

Menu::Menu()
{}

Menu::~Menu()
{
    std::size_t size = this->menu.size();
    for (std::size_t i = 0; i < size; ++i)
    {
        delete this->menu[i];
        this->menu[i] = nullptr;
    }
}

void Menu::addFood(double weight, unsigned int pieces, double price)
{
    try
    {
        this->menu.push_back(new Food(weight, pieces, price));
    }
    catch(const std::bad_alloc& ba)
    {
        std::cout << ba.what() << std::endl;
        throw std::bad_alloc();
    }
}

void Menu::removeFood(unsigned int id)
{
    std::size_t size = this->menu.size();
    for (std::size_t i = 0; i < size; ++i)
    {
        if (this->menu[i]->getId() == id)
        {
            delete this->menu[i];
            this->menu[i] = nullptr;
            this->menu.erase(this->menu.begin() + i);
            return;
        }
    }

    throw std::invalid_argument("Invalid id");
}

void Menu::print()
{
    std::size_t size = this->menu.size();
    for (std::size_t i = 0; i < size; ++i)
    {
        this->menu[i]->print();
    }
}

Food* Menu::getCheapestFood()
{
    std::size_t size = this->menu.size();
    if (size == 0)
    {
        std::cout << "No food" << std::endl;
        return nullptr;
    }

    std::size_t minIndex = 0;
    for (std::size_t i = 1; i < size; ++i)
    {
        if (this->menu[i]->getPrice() < this->menu[minIndex]->getPrice())
        {
            minIndex = i;
        }
    }

    return this->menu[minIndex];
}

std::size_t Menu::getSize()
{
    return this->menu.size();
}