#include <iostream>
#include <cstring>
#include "Student.h"
#include "FnGenerator.h"

Student::Student(const char* name, bool isEnrolled)
{
    char* buffer;

    try
    {
        buffer = new char[strlen(name) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    
    this->name = buffer;
    strcpy(this->name, name);
    this->facultyNumber = FnGenerator::generateId();
    this->isEnrolled = isEnrolled;
}

void Student::copy(const Student& other)
{
    char* buffer;

    try
    {
        buffer = new char[strlen(other.name) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    
    this->name = buffer;
    strcpy(this->name, other.name);
    this->facultyNumber = other.facultyNumber;
    this->isEnrolled = other.isEnrolled;
}

void Student::deallocate()
{
    if (this->name)
    {
        delete[] this->name;
    }
}

Student::Student(const Student& other)
{
    this->copy(other);
}

Student& Student::operator = (const Student& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

Student::~Student()
{
    this->deallocate();
}

std::ostream& operator << (std::ostream& out, const Student& student)
{
    out << "Name: " << student.name << std::endl;
    out << "Faculty number: " << student.facultyNumber;

    return out;
}

int Student::getFacultyNumber() const
{
    return this->facultyNumber;
}

bool Student::getIsEnrolled() const
{
    return this->isEnrolled;
}

void Student::setIsEnrolled()
{
    this->isEnrolled = true;
}