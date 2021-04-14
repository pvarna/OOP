#pragma once

#include "student.h"

const int INITIAL_CAPACITY = 2;
const int INCREASE_STEP = 2;

class University
{
private:
    Student** students;
    size_t size;
    size_t capacity;

    void copy(const University& other);
    void deallocate();
    void resize();

public:
    University();
    University(const University& other);
    University& operator = (const University& other);
    ~University();

    size_t getSize() const;

    void addStudent(const char* name, int facultyNumber, bool isEnrolled);
    void addStudent(const Student& student);

    University operator + (const University& university);
    Student& operator [] (size_t index);
};