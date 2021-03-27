#pragma once

class Teacher
{
private:
    char* name;
    char* teachingClass;

public:
    Teacher();
    Teacher(const char* name, const char* teachingClass);

    void input();
    void deallocateMemory();
    void copyTeacher(Teacher& teacher);
    void print();

    char* getName();
    char* getFN();
    double getAverageGrade();

    void setName(const char* wantedName);
    void setTeachingClass(const char* wantedClass);

    ~Teacher();
};