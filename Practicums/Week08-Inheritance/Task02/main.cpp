#include <iostream>
#include "Computer.h"

int main ()
{
    Computer myComputer("512", "3080", "i7", "8");
    Computer myComputer2("2014", "3090", "i7", "16");

    myComputer.print();
    std::cout << std::endl;
    myComputer2.print();

    return 0;
}