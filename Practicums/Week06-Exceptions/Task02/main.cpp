#include <iostream>
#include "backpack.h"

int main ()
{
    Backpack myBackpack(50, 50);

    Item item1("fenerche", 20, 25), item2("butilka voda", 20, 20);

    myBackpack.add(item1);
    myBackpack.add(item2);

    std::cout << myBackpack.getSize() << std::endl;
    std::cout << myBackpack.leftVolume() << std::endl;
    std::cout << myBackpack.leftWeight() << std::endl;
    std::cout << std::boolalpha << (myBackpack[0] == item1) << std::endl;
    std::cout << std::boolalpha << (myBackpack[1] == item2) << std::endl;

    Item item3("neshto", 15, 10);

    myBackpack.add(item3);

    return 0;
}