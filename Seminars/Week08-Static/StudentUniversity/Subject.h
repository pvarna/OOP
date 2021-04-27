#pragma once

#include <cstddef>
#include "Subject.h"
#include "University.h"
#include "consts.h"

class Subject
{
private:
    static University* university;
    int* facultyNumbers;
    
    std::size_t size;
    std::size_t capacity;

    void copy(const Subject& other);
    void deallocate();
    void resize();

public:
    static void setUniversity(University* university);

    Subject();
    Subject(const Subject& other);
    Subject& operator = (const Subject& other);
    ~Subject();

    void addFacultyNumber(int facultyNumber);
    void printStudentsWhoAreNotEnrolled();

    std::size_t getSize() const;

    Student& operator [] (std::size_t index);
};