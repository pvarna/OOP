#include <iostream>
#include <stdexcept>
#include "Subject.h"

University* Subject::university;

void Subject::setUniversity(University* university)
{
    Subject::university = university;
}

Subject::Subject()
{
    this->facultyNumbers = nullptr;
    try
    {
        this->facultyNumbers = new int[INITIAL_CAPACITY];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }

    this->capacity = INITIAL_CAPACITY;
    this->size = 0;
}

void Subject::copy(const Subject& other)
{
    int* buffer = nullptr;
    try
    {
        buffer = new int[other.capacity];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
    
    for (std::size_t i = 0; i < other.size; ++i)
    {
        buffer[i] = other.facultyNumbers[i];
    }

    this->facultyNumbers = buffer;
    this->capacity = other.capacity;
    this->size = other.size;
}

void Subject::deallocate()
{
    if (this->facultyNumbers)
    {
        delete[] this->facultyNumbers;
    }
}

Subject::Subject(const Subject& other)
{
    this->copy(other);
}

Subject& Subject::operator = (const Subject& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

Subject::~Subject()
{
    this->deallocate();
}

void Subject::resize()
{
    int* buffer = nullptr;
    try
    {
        buffer = new int[this->capacity * INCREASE_STEP];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
    
    for (std::size_t i = 0; i < this->size; ++i)
    {
        buffer[i] = this->facultyNumbers[i];
    }

    this->deallocate();
    this->facultyNumbers = buffer;
    this->capacity = this->capacity * INCREASE_STEP; 
}

void Subject::addFacultyNumber(int facultyNumber)
{
    if (this->size < this->university->getSize())
    {
        if (this->size == this->capacity)
        {
            this->resize();
        }

        this->facultyNumbers[this->size++] = facultyNumber;
        this->university->setHasSubject(facultyNumber);
    }
}

void Subject::printStudentsWhoAreNotEnrolled()
{
    int counter = 0;
    for (std::size_t i = 0; i < this->university->getSize(); ++i)
    {
        if (!(*this->university)[i].getIsEnrolled())
        {
            std::cout << (*this->university)[i] << std::endl;
            ++counter;
        }
    }

    if (counter == 0)
    {
        std::cout << "All students in the university are enrolled to a subject" << std::endl;
    }
}

Student& Subject::operator [] (std::size_t index)
{
    int wantedFacultyNumber = this->facultyNumbers[index];
    
    for (std::size_t i = 0; i < this->university->getSize(); ++i)
    {
        if ((*this->university)[i].getFacultyNumber() == wantedFacultyNumber)
        {
            return (*this->university)[i];
        }
    }

    throw std::invalid_argument("Invalid index");
}

std::size_t Subject::getSize() const
{
    return this->size;
}