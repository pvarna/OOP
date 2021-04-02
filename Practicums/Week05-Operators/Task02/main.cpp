#include <iostream>
#include "washingMachine.h"

int main ()
{
    int n;

    std::cin >> n;
    std::cin.ignore();

    WashingMachine* washingMachines = new(std::nothrow) WashingMachine[n];
    if (!washingMachines)
    {
        std::cout << "Memory problem" << std::endl;
        return 1;
    }

    std::cin >> washingMachines[0];
    WashingMachine best = washingMachines[0];

    for (int i = 1; i < n; ++i)
    {
        std::cin >> washingMachines[i];
        if (washingMachines[i] > best)
        {
            best = washingMachines[i];
        }
    }

    std::cout << best << std::endl;

    delete[] washingMachines;
}