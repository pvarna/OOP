#include <iostream>
#include <cstring>
#include "sorting.h"

/*
template <typename T>
void sortAllTypes(T* people, sortingFunctions<T> sortingFunction, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
            if(sortingFunction(people[i], people[j]))
            {
                std::swap(people[i], people[j]);
            }
        }
    }
}

template <typename T>
bool nameSortAsc(T first, T second)
{
    return strcmp(first.getName(), second.getName()) > 0;
}

template <typename T>
bool nameSortDesc(T first, T second)
{
    return strcmp(first.getName(), second.getName()) < 0;
}*/

void sortAllTypes(Student* students, sortingFunctions sortingFunction, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
            if(sortingFunction(students[i], students[j]))
            {
                std::swap(students[i], students[j]);
            }
        }
    }
}

bool nameSortAsc(Student first, Student second)
{
    return strcmp(first.getName(), second.getName()) > 0;
}

bool nameSortDesc(Student first, Student second)
{
    return strcmp(first.getName(), second.getName()) < 0;
}

bool fnSortAsc(Student first, Student second)
{
    return strcmp(first.getFN(), second.getFN()) > 0;
}

bool fnSortDesc(Student first, Student second)
{
    return strcmp(first.getFN(), second.getFN()) < 0;
}

bool averageScoreSortAsc(Student first, Student second)
{
    return first.getAverageGrade() < second.getAverageGrade();
}

bool averageScoreSortDesc(Student first, Student second)
{
    return first.getAverageGrade() > second.getAverageGrade();
}