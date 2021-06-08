#include <iostream>
#include <memory>
#include "park.h"

int main ()
{
    std::string name;
    std::getline(std::cin, name);

    Park* park = new Park(name);

    std::cout << park->getName() << std::endl;

    delete park;

    std::unique_ptr<Park> parkUnique(new Park(name));

    std::cout << park->getName() << std::endl;

    std::shared_ptr<Park> parkShared1(new Park(name));
    std::shared_ptr<Park> parkShared2(parkShared1);
    std::shared_ptr<Park> parkShared3(parkShared2);

    //std::weak_ptr<Park> parkWeak1(parkShared1);
    //std::weak_ptr<Park> parkWeak2(parkShared1);


    return 0;
}