#include <iostream>
#include <cstring>
#include "university.h"

bool nameSort(Student first, Student second, Order order)
{
    int comparison = strcmp(first.getName(), second.getName());
    return (order == asc) ? (comparison > 0) : (comparison < 0);
}

bool fnSort(Student first, Student second, Order order)
{
    int comparison = strcmp(first.getFN(), second.getFN());
    return (order == asc) ? (comparison > 0) : (comparison < 0);
}

bool averageGradeSort(Student first, Student second, Order order)
{
    return (order == asc) ? (first.getAverageGrade() > second.getAverageGrade()) : (first.getAverageGrade() < second.getAverageGrade());
}

sortingFunction University::getComparison(Field field)
{
    switch (field)
    {
        case name:
            return nameSort;
        case fn:
            return fnSort;
        case averageScore:
            return averageGradeSort;
        default:
            return nameSort;
    }
}

void University::createStudents(Student* people, size_t size)
{
    this->students = new(std::nothrow) Student[size + FREE_SPACE_STUDENTS];
    if (!this->students)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        this->students[i] = people[i];
    }

    this->numberStudents = size;
    this->capacity = size + FREE_SPACE_STUDENTS;
}

void University::resize()
{
    this->capacity += FREE_SPACE_STUDENTS;

    Student* newStudents = new Student[this->capacity];
    for (int i = 0; i < this->numberStudents; ++i)
    {  
        newStudents[i] = this->students[i];
    }

    delete[] this->students;
    this->students = newStudents;
}

void University::sort(Field field, Order order)
{
    for (int i = 0; i < this->numberStudents; ++i)
    {
        for (int j = i+1; j < this->numberStudents; ++j)
        {
            if (getComparison(field)(students[i], students[j], order))
            {
                std::swap(students[i], students[j]);
            }
        }
    }
}

void University::printStudents()
{
    for (int i = 0; i < this->numberStudents; ++i)
    {
        this->students[i].print();
    }
}

University& University::operator += (const Student& student)
{
    if (this->numberStudents == this->capacity)
    {
        this->resize();
    }

    bool doesOccurre = false;
    for (int i = 0; i < this->numberStudents; ++i)
    {
        if (this->students[i] == student)
        {
            doesOccurre = true;
            break;
        }
    }

    if (!doesOccurre)
    {
        this->students[this->numberStudents++] = student;
    }

    return *this;
}

University& University::operator -= (const Student& student)
{
    int index = -1;
    for (int i = 0; i < this->numberStudents; ++i)
    {
        if (this->students[i] == student)
        {
            index = i;
            break;
        }
    }

    for (int i = index; i < this->numberStudents - 1; ++i)
    {
        students[i] = students[i+1];
    }

    --this->numberStudents;

    return *this;
}

Student& University::operator [] (int index)
{
    if (index >= this->numberStudents)
    {
        std::cout << "There is no such index" << std::endl;
    }
    
    return this->students[index];
}
void University::printSizeCapacity()
{
    std::cout << "Size: " << this->numberStudents << std::endl;
    std::cout << "Capacity: " << this->capacity << std::endl;
    std::cout << (double)this->numberStudents/(double)this->capacity*100 << "% full" << std::endl;
}