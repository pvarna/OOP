#ifndef FUNCTIONS_H
#define FUNCTION_H

struct Grade
{
    char* subject;
    double grade;

    void readGrade();
};

struct Student
{
    char* name;
    char EGN[10];
    char facultyNumber[5];
    Grade grades[5];

    void readStudent();
    void fixName();
    double averageScore();
    char* firstLastName();
};

struct Students
{
    Student students[100];
    int numberOfStudents = 0;

    void addStudent();
    void printStudentsBornInMarch();
    void printStudentWithHighestScore();
    void deallocateMemory();
};

char toUpper(char ch);

void printMenu();

#endif