#include <iostream>
#include <vector>

int main ()
{
    std::vector<int> elements;
    std::size_t n;

    std::cout << "How many elements you want to add?" << std::endl;
    std::cin >> n;

    for (std::size_t i = 0; i < n; ++i)
    {
        int number;
        std::cin >> number;
        elements.push_back(number);
    }

    for (std::vector<int>::const_iterator i = elements.begin(); i != elements.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}