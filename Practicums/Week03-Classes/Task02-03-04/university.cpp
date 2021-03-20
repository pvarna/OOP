#include <iostream>
#include <cstring>
#include "university.h"
#include "student.h"
#include "sorting.h"

void University::createStudents(Student* students, size_t size)
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

void University::createTeachers(Teacher* teachers, size_t size)
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

/*template <typename T>
void University::sort(T* people, Field field, Order order, size_t size)
{
    switch (field)
    {
        case 0:
            if (order == 0)
            {
                sortAllTypes<T>(people, nameSortAsc<T>, size);
            }
            else
            {
                sortAllTypes<T>(people, nameSortDesc<T>, size);
            }
            break;
        case 1:
            if (order == 0)
            {
                sortAllTypes<Student>(people, fnSortAsc, size);
            }
            else
            {
                sortAllTypes<Student>(people, fnSortDesc, size);
            }
            break;
        case 2:
            if (order == 0)
            {
                sortAllTypes<Student>(people, averageScoreSortAsc, size);
            }
            else
            {
                sortAllTypes<Student>(people, averageScoreSortDesc, size);
            }
            break;
        default:
            return;       
    }
}*/

void University::sort(Field field, Order order)
{
    switch (field)
    {
        case 0:
            if (order == 0)
            {
                sortAllTypes(this->listOfStudents, nameSortAsc, numberOfStudents);
            }
            else
            {
                sortAllTypes(this->listOfStudents, nameSortDesc, numberOfStudents);
            }
            break;
        case 1:
            if (order == 0)
            {
                sortAllTypes(this->listOfStudents, fnSortAsc, numberOfStudents);
            }
            else
            {
                sortAllTypes(this->listOfStudents, fnSortDesc, numberOfStudents);
            }
            break;
        case 2:
            if (order == 0)
            {
                sortAllTypes(this->listOfStudents, averageScoreSortAsc, numberOfStudents);
            }
            else
            {
                sortAllTypes(this->listOfStudents, averageScoreSortDesc, numberOfStudents);
            }
            break;
        default:
            return;       
    }
}

void University::printAllStudents()
{
    for (int i = 0; i < this->numberOfStudents; ++i)
    {
        this->listOfStudents[i].printStudentInfo();
    }
}

void University::printAllTeachers()
{
    for (int i = 0; i < this->numberOfTeachers; ++i)
    {
        this->listOfTeachers[i].printTeacherInfo();
    }
}