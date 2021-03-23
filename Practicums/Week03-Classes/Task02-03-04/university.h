// Definitions of functions/methods are not separated into another source file because of problem with 'temlate' 

#pragma once

#include <iostream>
#include <cstring>
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

enum Role
{
    students,
    teachers
};

template <typename T>
using sortingFunction = bool (*) (T, T);

template <typename T>
void sortAllTypes(T* people, sortingFunction<T> sortingFunction, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
            if (sortingFunction(people[i], people[j]))
            {
                std::swap(people[i], people[j]);
            }
        }
    }
}

template <typename T>
bool nameSortAsc(T first, T second)
{
    return (strcmp(first.getName(), second.getName()) > 0);
}

template <typename T>
bool nameSortDesc(T first, T second)
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

bool averageGradeSortAsc(Student first, Student second)
{
    return first.getAverageGrade() > second.getAverageGrade();
}

bool averageGradeSortDesc(Student first, Student second)
{
    return first.getAverageGrade() < second.getAverageGrade();
}

class University
{
    private:
        Student* listOfStudents;
        Teacher* listOfTeachers;
        size_t numberOfStudents;
        size_t numberOfTeachers;

    public:

        void createStudents(Student* students, size_t size)
        {
            this->listOfStudents = new(std::nothrow) Student[size];
            if (!this->listOfStudents)
            {
                std::cout << "Memory problem!" << std::endl;
                return;
            }

            for (int i = 0; i < size; ++i)
            {
                students[i].copyStudent(this->listOfStudents[i]);
            }

            this->numberOfStudents = size;
        }
        void createTeachers(Teacher* teachers, size_t size)
        {
            this->listOfTeachers = new(std::nothrow) Teacher[size];
            if (!this->listOfTeachers)
            {
                std::cout << "Memory problem!" << std::endl;
                return;
            }

            for (int i = 0; i < size; ++i)
            {
                teachers[i].copyTeacher(this->listOfTeachers[i]);
            }

            this->numberOfTeachers = size;
        }

        void sort(Field field, Order order, Role role)
        {
            if (role == teachers)
            {
                if (field != name)
                {
                    std::cout << "Invalid operation" << std::endl;
                    return;
                }
                else
                {
                    if (order == asc)
                    {
                        sortAllTypes<Teacher>(listOfTeachers, nameSortAsc<Teacher>, numberOfTeachers);
                    }
                    else
                    {
                        sortAllTypes<Teacher>(listOfTeachers, nameSortDesc<Teacher>, numberOfTeachers);
                    }
                }
            }

            switch (field)
            {
            case name:
                if (order == asc)
                {
                    sortAllTypes<Student>(listOfStudents, nameSortAsc<Student>, numberOfStudents);
                }
                else
                {
                    sortAllTypes<Student>(listOfStudents, nameSortDesc<Student>, numberOfStudents);
                }
                break;
            case fn:
                if (order == asc)
                {
                    sortAllTypes<Student>(listOfStudents, fnSortAsc, numberOfStudents);
                }
                else
                {
                    sortAllTypes<Student>(listOfStudents, fnSortDesc, numberOfStudents);
                }
                break;
            case averageScore:
                if (order == asc)
                {
                    sortAllTypes<Student>(listOfStudents, averageGradeSortAsc, numberOfStudents);
                }
                else
                {
                    sortAllTypes<Student>(listOfStudents, averageGradeSortDesc, numberOfStudents);
                }
                break;
            default:
                std::cout << "Invalid operation" << std::endl;
                return;
            }
        }

        void printAllStudents()
        {
            for (int i = 0; i < this->numberOfStudents; ++i)
            {
                this->listOfStudents[i].printStudentInfo();
            }
        }
        void printAllTeachers()
        {
            for (int i = 0; i < this->numberOfTeachers; ++i)
            {
                this->listOfTeachers[i].printTeacherInfo();
            }
        }
};