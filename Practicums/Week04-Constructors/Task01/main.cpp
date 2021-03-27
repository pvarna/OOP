#include <iostream>
#include "pace.h"

int main ()
{
    Pace runner1(1, 0), runner2(5);

    std::cout << runner1.getSpeed() << std::endl;

    int* pace = runner2.getPace();
    std::cout << pace[0] << " " << pace[1] << std::endl;

    delete[] pace;
}