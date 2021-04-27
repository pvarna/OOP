#pragma once

#include <cstddef>
#include "Student.h"
#include "consts.h"

class University
{
private:
    Student** students;
    std::size_t size;
    std::size_t capacity;

    void copy(const University& other);
    void deallocate();
    void resize();

public:
    University();
    University(const University& other);
    University& operator = (const University& other);
    ~University();

    std::size_t getSize() const;

    void addStudent(const char* name, bool isEnrolled);
    void addStudent(const Student& student);

    University operator + (const University& university);
    Student& operator [] (std::size_t index);

    void setHasSubject(int facultyNumber);
};