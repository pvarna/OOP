#include "functions.h"
#include <iostream>

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