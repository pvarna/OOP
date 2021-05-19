#include "menu.h"
#include <iostream>

int main ()
{
    Menu menu;

    menu.addFood(1000, 9, 20.40);
    menu.addFood(800, 5, 12);
    menu.addFood(500, 1, 10);

    std::cout << "CHEAPEST: " << std::endl;
    menu.getCheapestFood()->print();

    std::cout << std::endl;
    menu.removeFood(1);

    menu.print();

    return 0;
}