#include <iostream>
#include "ComputerShop.h"
#include "ConsultantUtils.h"

int main ()
{
    Computer computer1("Lenovo", "i7", "3080", 1024, 5, 5, 1800);
    Computer computer2("Lenovo", "i7", "3080", 1024, 5, 5, 1800);
    Computer computer3("Lenovo", "i7", "3080", 1024, 5, 5, 1800);
    Computer computer4("Dell", "i6", "3060", 756, 2, 10, 1200);
    Computer computer5("Dell", "i6", "3060", 756, 2, 10, 1200);
    Computer computer6("Dell", "i6", "3060", 756, 2, 10, 1200);
    Computer computer7("Dell", "i6", "3060", 756, 2, 10, 1200);
    Computer computer8("Acer", "i3", "2000", 200, 3, 5, 900);
    Computer computer9("Asus", "i7", "5000", 2048, 4, 6, 2200);
    
    ComputerShop myShop("Pesho's shop", 5);
    myShop.addComputer(computer1);
    myShop.addComputer(computer2);
    myShop.addComputer(computer3);
    myShop.addComputer(computer4);
    myShop.addComputer(computer5);
    myShop.addComputer(computer6);
    myShop.addComputer(computer7);
    myShop.addComputer(computer8);
    myShop.addComputer(computer9);

    //myShop.buyComputer(2000, "Mac");

    //std::cout << myShop;

    std::size_t countGoodForGaming;
    Computer* goodForGaming = myShop.filter(ConsultantUtils::isGoodForTravel, countGoodForGaming);

    std::cout << countGoodForGaming << std::endl;

    for (std::size_t i = 0; i < countGoodForGaming; ++i)
    {
        std::cout << goodForGaming[i] << std::endl;
    }

    std::size_t countGoodForTravel;
    Computer* goodForTravel = myShop.filter(ConsultantUtils::isGoodForTravel, countGoodForTravel);

    std::cout << countGoodForTravel << std::endl;

    for (std::size_t i = 0; i < countGoodForTravel; ++i)
    {
        std::cout << goodForTravel[i] << std::endl;
    }

    delete[] goodForGaming;
    delete[] goodForTravel;

    return 0;
}