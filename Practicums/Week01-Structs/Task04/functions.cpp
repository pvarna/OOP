#include "functions.h"
#include <iostream>

void Runner::readRunner()
{
    std::cout << "Please enter the name of the runner: ";
    std::cin.getline(name, 100);

    std::cout << "Please enter the results of the 12 competitions in seconds:" << std::endl;
    for(int i = 0; i < 12; ++i)
    {
        std::cout << "Competition #" << i+1 << ": ";
        std::cin >> results[i];
    }
    std::cin.ignore();
}

double Runner::averageSpeed()
{
    double sumTimes = 0;
    for (int i = 0; i < 12; ++i)
    {
        sumTimes += results[i];
    }

    sumTimes /= 3600;

    double distance = 42*12;

    return distance/sumTimes;
}

int Runner::beatNtime(Runner runnerB)
{
    int counter = 0;
    for (int i = 0; i < 12; ++i)
    {
        if (results[i] < runnerB.results[i])
        {
            ++counter;
        }
    }

    return counter;
}