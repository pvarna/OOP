#include <iostream>
#include <cstring>
#include "university.h"
#include "student.h"

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