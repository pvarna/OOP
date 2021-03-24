#include <iostream>
#include "person.h"

int main ()
{
    Person teo("Teodor", 19, true);

    teo.print();

    Person lyubo;

    lyubo = teo;

    std::cout << lyubo;

    Person pesho;

    std::cin >> pesho;

    std::cout << pesho;

    Person soncheMakaronche;

    std::cin >> soncheMakaronche;

    std::cout << soncheMakaronche;

    return 0;
}