#include "functions.h"
#include <iostream>

int main ()
{
    int n;

    std::cout << "Please enter the number of runners: ";
    std::cin >> n;
    std::cin.ignore();

    Runner* runners = new(std::nothrow) Runner[n];

    for (int i = 0; i < n; ++i)
    {
        std::cout << "Runner #" << i+1 << ":" << std::endl;
        runners[i].readRunner();
    }

    double minSpeed = runners[0].averageSpeed();
    int minIndex = 0;

    for (int i = 1; i < n; ++i)
    {
        double currentSpeed = runners[i].averageSpeed();
        if (currentSpeed < minSpeed)
        {
            minSpeed = currentSpeed;
            minIndex = i;
        }
    }

    std::cout << "Runner with slowest average speed: " << runners[minIndex].name << ", Average speed: " << minSpeed << " km/h" << std::endl;

    std::cout << "Times Runner 1 is faster than Runner 2: " << runners[0].beatNtime(runners[1]) << std::endl;
    std::cout << "Times Runner 2 is faster than Runner 1: " << runners[1].beatNtime(runners[0]) << std::endl;

    delete[] runners;

    return 0;
}