#include "park.h"
#include <iostream>
#include <vector>

int main ()
{
    std::vector<Park> parks;
    std::size_t n;

    std::cout << "How many parks you want to add?" << std::endl;
    std::cin >> n;
    std::cin.ignore();

    for (std::size_t i = 0; i < n; ++i)
    {
        std::string name;
        std::getline(std::cin, name);

        parks.push_back(Park(name));
    }

    std::string toBeRemoved;
    std::cout << "Enter the name of the park you want to remove: ";
    std::getline(std::cin, toBeRemoved);

    for (std::vector<Park>::iterator i = parks.begin(); i != parks.end(); ++i)
    {
        if ((*i).getName() == toBeRemoved)
        {
            parks.erase(i);
        }
    }

    for (std::vector<Park>::const_iterator i = parks.begin(); i != parks.end(); ++i)
    {
        std::cout << i->getName() << std::endl;
    }

    return 0;
}