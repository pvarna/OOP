#include <iostream>
#include "functions.h"

int main ()
{
    DynArray myArray = create();

    push_back(myArray, 10);
    push_back(myArray, 20);
    push_back(myArray, 30);
    push_back(myArray, 40);
    push_back(myArray, 50);
    push_back(myArray, 60);
    push_back(myArray, 70);
    push_back(myArray, 80);
    push_back(myArray, 90);

    std::cout << "Size: " << myArray.size << std::endl;
    std::cout << "Capacity: " << myArray.capacity << std::endl;
    for (int i = 0; i < myArray.size; ++i)
    {
        std::cout << "numbers[" << i << "] = " << myArray.numbers[i] << std::endl;
    }

    pop_back(myArray);
    std::cout << std::endl;

    std::cout << "Size: " << myArray.size << std::endl;
    std::cout << "Capacity: " << myArray.capacity << std::endl;
    for (int i = 0; i < myArray.size; ++i)
    {
        std::cout << "numbers[" << i << "] = " << myArray.numbers[i] << std::endl;
    }

    remove(myArray, 3);
    std::cout << std::endl;

    std::cout << "Size: " << myArray.size << std::endl;
    std::cout << "Capacity: " << myArray.capacity << std::endl;
    for (int i = 0; i < myArray.size; ++i)
    {
        std::cout << "numbers[" << i << "] = " << myArray.numbers[i] << std::endl;
    }

    std::cout << std::endl;

    std::cout << "numbers[3] = " << get(myArray, 3) << std::endl;

    return 0;
}