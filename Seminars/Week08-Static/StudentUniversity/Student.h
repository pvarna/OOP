#pragma once

#include <fstream>

class Student
{
private:
    char* name;
    int facultyNumber;
    bool isEnrolled;

    void copy(const Student& other);
    void deallocate();
    
public:
    Student(const char* name, bool isEnrolled);
    Student(const Student& other);
    Student& operator = (const Student& other);
    ~Student();

    int getFacultyNumber() const;
    bool getIsEnrolled() const;

    void setIsEnrolled();

    friend std::ostream& operator << (std::ostream& out, const Student& student);
};