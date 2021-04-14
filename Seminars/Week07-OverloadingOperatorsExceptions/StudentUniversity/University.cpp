#include <iostream>
#include <cstring>
#include "University.h"

University::University()
{
    try
    {
        this->students = new Student*[INITIAL_CAPACITY];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(0); //???
    }

    for (int i = 0; i < INITIAL_CAPACITY; ++i)
    {
        this->students[i] = nullptr;
    }

    this->capacity = INITIAL_CAPACITY;
    this->size = 0;    
}

void University::copy(const University& other)
{
    Student** buffer = nullptr;
    try
    {
        buffer = new Student*[other.capacity];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (int i = 0; i < other.capacity; ++i)
    {
        if (i < other.size)
        {
            buffer[i] = new Student(*other.students[i]);
        }
        else
        {
            buffer[i] = nullptr;
        }
    }

    this->students = buffer;
    this->size = other.size;
    this->capacity = other.capacity;
    
}

void University::deallocate()
{
    for (int i = 0; i < this->capacity; ++i)
    {
        if (this->students[i])
        {
            delete this->students[i];
        }
    }

    delete[] this->students;
}

void University::resize()
{
    size_t newCapacity = this->capacity * INCREASE_STEP;

    Student** newStudents = nullptr;
    try
    {
        newStudents = new Student*[newCapacity];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (int i = 0; i < newCapacity; ++i)
    {
        if (i < this->size)
        {
            newStudents[i] = new Student(*this->students[i]);
        }
        else
        {
            newStudents[i] = nullptr;
        }
    }

    this->deallocate();
    this->students = newStudents;
    this->capacity = newCapacity;
}

University::University(const University& other)
{
    this->copy(other);
}

University& University::operator = (const University& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

University::~University()
{
    this->deallocate();
}

void University::addStudent(const char* name, int facultyNumber, bool isEnrolled)
{
    if (this->size >= this->capacity)
    {
        this->resize();
    }

    this->students[this->size++] = new Student(name, facultyNumber, isEnrolled);
}

void University::addStudent(const Student& student)
{
    if (this->size >= this->capacity)
    {
        this->resize();
    }

    this->students[this->size++] = new Student(student);
}

University University::operator + (const University& university)
{
    University result = *this;

    for (int i = 0; i < university.size; ++i)
    {
        result.addStudent(*university.students[i]);
    }

    return result;
}

Student& University::operator [] (size_t index)
{
    if (index >= this->size)
    {
        throw std::out_of_range("Invalid index");
    }

    return *this->students[index];
}

size_t University::getSize() const
{
    return this->size;
}