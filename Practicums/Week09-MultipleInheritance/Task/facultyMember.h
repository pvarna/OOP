#pragma once

#include "student.h"
#include "lecturer.h"
#include <fstream>

class FacultyMember : public Student, public Lecturer
{
public:
    FacultyMember();
    FacultyMember(std::string name, unsigned int number, unsigned int salary);

    std::string getName() const;
    unsigned int getNumber() const;
    unsigned int getSalary() const;

    void write(std::ofstream& file);
    void read(std::ifstream& file);

    friend std::istream& operator >> (std::istream& in, FacultyMember& facultyMember);
    friend std::ostream& operator << (std::ostream& out, const FacultyMember& facultyMember);
};