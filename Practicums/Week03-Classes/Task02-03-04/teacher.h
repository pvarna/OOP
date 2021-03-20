#pragma once

class Teacher
{
private:
    char* name;
    char* teachingClass;

public:
    void input();
    void deallocateMemory();
    void copyTeacher(Teacher& teacher);
    void printTeacherInfo();

    char* getName();

    void setName(const char* wantedName);
    void setTeachingClass(const char* wantedClass);
};