#pragma once

#include "student.h"

const int FREE_SPACE_STUDENTS = 10;

enum Field
{
    name,
    fn,
    averageScore
};

enum Order
{
    asc, 
    desc
};

using sortingFunction = bool (*) (Student, Student, Order);

bool nameSort(Student first, Student second, Order order);

bool fnSort(Student first, Student second, Order order);

bool averageGradeSort(Student first, Student second, Order order);

class University
{
    private:
        Student* students;
        size_t numberStudents;
        size_t capacity;

        sortingFunction getComparison(Field field);

        void resize();

    public:
        void createStudents(Student* people, size_t size);
        void sort(Field field, Order order);
        void printStudents();

        University& operator += (const Student& student);
        University& operator -= (const Student& student);

        size_t getSize() const;
        size_t getCapacity() const;

        Student& operator [] (int index); 

        void printSizeCapacity();
};