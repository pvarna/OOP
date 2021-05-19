#pragma once

#include "food.h"
#include <vector>

class Menu
{
private:
    std::vector<Food*> menu;

public:
    Menu();
    Menu(const Menu& other) = delete;
    Menu& operator = (const Menu& other) = delete;
    ~Menu();
    void addFood(double weight, unsigned int pieces, double price);
    void removeFood(unsigned int id);
    void print();
    Food* getCheapestFood();

    std::size_t getSize();
};