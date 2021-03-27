#include <iostream>
#include <cstring>
#include "teacher.h"

Teacher::Teacher()
{
    this->name = nullptr;
    this->teachingClass = nullptr;
}

Teacher::Teacher(const char* name, const char* teachingClass)
{
    size_t size = strlen(name);
    this->name = new char[size + 1];
    strcpy(this->name, name);\

    size = strlen(teachingClass);
    this->teachingClass = new char[size + 1];
    strcpy(this->teachingClass, teachingClass);

}

Teacher::~Teacher()
{
    deallocateMemory();
}

void Teacher::input()
{
    char buffer[100];

    std::cout << "Please enter the name of the teacher: ";
    std::cin.getline(buffer, 100);
    size_t size = strlen(buffer);
    this->name = new(std::nothrow) char[size + 1];
    strcpy(this->name, buffer);
    this->name[size] = '\0';

    std::cout << "Please enter the class the teacher teaches: ";
    std::cin.getline(buffer, 100);
    size = strlen(buffer);
    this->teachingClass = new(std::nothrow) char[size + 1];
    strcpy(this->teachingClass, buffer);
    this->teachingClass[size] = '\0';
}

void Teacher::deallocateMemory()
{
    delete[] this->name;
    delete[] this->teachingClass;
}

void Teacher::copyTeacher(Teacher& teacher)
{
    teacher.setName(this->name);
    teacher.setTeachingClass(this->teachingClass);
}

char* Teacher::getName()
{
    return this->name;
}

char* Teacher::getFN()
{
    return nullptr;
}

double Teacher::getAverageGrade()
{
    return 2;
}

void Teacher::print()
{
    std::cout << this->name << ", " << this->teachingClass << std::endl;
}

void Teacher::setName(const char* wantedName)
{
    size_t size = strlen(wantedName);
    this->name = new(std::nothrow) char[size + 1];
    if (!this->name)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(this->name, wantedName);
    this->name[size] = '\0';
}

void Teacher::setTeachingClass(const char* wantedClass)
{
    size_t size = strlen(wantedClass);
    this->teachingClass = new(std::nothrow) char[size + 1];
    if (!this->teachingClass)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(this->teachingClass, wantedClass);
    this->teachingClass[size] = '\0';
}