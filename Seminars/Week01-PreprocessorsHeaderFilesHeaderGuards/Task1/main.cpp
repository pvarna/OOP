#include <iostream>
#include "functionsDeclarations.h"

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

DynArray create()
{
    DynArray array;
    array.capacity = 2;
    array.size = 0;
    array.numbers = new(std::nothrow) int[array.capacity];

    return array;
}

void push_back(DynArray& array, int element)
{
    if (array.size == array.capacity)
    {
        resize(array);
    }

    array.numbers[array.size] = element;
    ++array.size;
}

void resize(DynArray& array)
{
    int* old = array.numbers;

    array.capacity *= 2;
    
    array.numbers = new(std::nothrow) int[array.capacity];

    for (int i = 0; i < array.size; ++i)
    {
        array.numbers[i] = old[i];
    }

    delete[] old;
}

void pop_back(DynArray& array)
{
    --array.size;
}

int get(DynArray array, int index)
{
    return array.numbers[index];
}

void remove(DynArray& array, int index)
{
    for (int i = index; i < array.size - 1; ++i)
    {
        array.numbers[i] = array.numbers[i+1];
    }

    --array.size;
}