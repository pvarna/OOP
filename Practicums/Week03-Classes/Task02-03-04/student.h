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
    Student();
    Student(const char* name, const char* EGN, const char* FN, 
            double grade1, double grade2, double grade3, double grade4, double grade5);
    void input();
    double getAverageGrade();
    void print();
    void printFNAndGrades();

    void deallocateMemory();

    void copyStudent(Student& student);

    char* getName();
    char* getFN();

    void setName(const char* wantedName);
    void setEGN(const char* wantedEGN);
    void setFacultyNumber(const char* wantedFN);
    void setGrades(Grade* wantedGrades);

    ~Student();
};
