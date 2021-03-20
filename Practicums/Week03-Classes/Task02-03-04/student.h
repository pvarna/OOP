#pragma once

#include "grade.h"

class Student
{
private:
    char* name;
    char EGN[11];
    char facultyNumber[7];
    Grade grades[5];

public:
    void input();
    double getAverageGrade();
    void printStudentInfo();
    void printFNAndGrades();

    void deallocateMemory();

    void copyStudent(Student& student);

    char* getName();
    char* getFN();

    void setName(const char* wantedName);
    void setEGN(const char* wantedEGN);
    void setFacultyNumber(const char* wantedFN);
    void setGrades(Grade* wantedGrades);
};
