#pragma once

#include <iostream>
#include "student.h"
#include "teacher.h"

/*template <typename T>
using sortingFunctions = bool (*) (T, T);

template <typename T>
void sortAllTypes(T* people, sortingFunctions<T> sortingFunction, size_t size);

template <typename T>
bool nameSortAsc(T first, T second);
template <typename T>
bool nameSortDesc(T first, T second);*/

typedef bool (*sortingFunctions) (Student first, Student second);

void sortAllTypes(Student* students, sortingFunctions sortingFunction, size_t size);

bool nameSortAsc(Student first, Student second);
bool nameSortDesc(Student first, Student second);

bool fnSortAsc(Student first, Student second);
bool fnSortDesc(Student first, Student second);

bool averageScoreSortAsc(Student first, Student second);
bool averageScoreSortDesc(Student first, Student second);