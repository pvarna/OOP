#pragma once

#include <iostream>
#include "student.h"
#include "teacher.h"

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

class University
{
    private:
        Student* listOfStudents;
        Teacher* listOfTeachers;
        size_t numberOfStudents;
        size_t numberOfTeachers;

    public:
        /*Student* listOfStudents;
        Teacher* listOfTeachers;
        size_t numberOfStudents;
        size_t numberOfTeachers;*/

        void createStudents(Student* students, size_t size);
        void createTeachers(Teacher* teachers, size_t size);

        //template <typename T>
        //void sort(T* people, Field field, Order order, size_t size);

        void sort(Field field, Order order);

        void printAllStudents();
        void printAllTeachers();
};