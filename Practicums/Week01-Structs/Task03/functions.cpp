#include "functions.h"
#include <iostream>
#include <cstring>

void Grade::readGrade()
{
    char buffer[100];
    size_t size;

    std::cout << "Please enter the name of the subject: ";
    std::cin.getline(buffer, 100);
    size = strlen(buffer);
    subject = new(std::nothrow) char[size];
    strcpy(subject, buffer);

    std::cout << "Please enter the grade: ";
    std::cin >> grade;
    std::cin.ignore();   
}

void Student::readStudent()
{
    char buffer[100];
    size_t size;

    std::cout << "Please enter the name of the student: ";
    std::cin.getline(buffer, 100);
    size = strlen(buffer);
    name = new(std::nothrow) char[size];
    strcpy(name, buffer);

    std::cout << "Please enter the EGN of the student: ";
    std::cin >> EGN;
    std::cin.ignore();

    std::cout << "Please enter the faculty number of the student: ";
    std::cin >> facultyNumber;
    std::cin.ignore();

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Subject #" << i+1 << std::endl;
        grades[i].readGrade();
    }
}

char toUpper(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        ch = ch - ('a' - 'A');
    }

    return ch;
}

void Student::fixName()
{
    name[0] = toUpper(name[0]);
    int namesFixed = 1;
    int index = 1;
    while (namesFixed < 3)
    {
        if (name[index] == ' ')
        {
            name[index+1] = toUpper(name[index+1]);
            ++index;
            ++namesFixed;
        }
        ++index;
    }
}

double Student::averageScore()
{
    double sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        sum += grades[i].grade;
    }

    return sum/5;
}

void Students::addStudent()
{
    Student newStudent;

    newStudent.readStudent();
    newStudent.fixName();

    students[numberOfStudents++] = newStudent;
}

void Students::printStudentsBornInMarch()
{
    if (numberOfStudents == 0)
    {
        std::cout << "Please first enter some students" << std::endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < numberOfStudents; ++i)
    {
        if (students[i].EGN[3] == '3')
        {
            std::cout << students[i].name << ", Average score: " << students[i].averageScore() << std::endl;
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "There aren't any students born in March" << std::endl;
    }
}

void Students::printStudentWithHighestScore()
{
    if (numberOfStudents == 0)
    {
        std::cout << "Please first enter some students" << std::endl;
        return;
    }

    double maxScore = students[0].averageScore();
    int maxIndex = 0;

    for (int i = 1; i < numberOfStudents; ++i)
    {
        if (students[i].averageScore() > maxScore)
        {
            maxScore = students[i].averageScore();
            maxIndex = i;
        }
    }

    std::cout << students[maxIndex].name << ", Score: " << maxScore << std::endl;
}

void Students::deallocateMemory()
{
    for (int i = 0; i < numberOfStudents; ++i)
    {
        delete[] students[i].name;
        for (int j = 0; j < 5; ++j)
        {
            delete[] students[i].grades[j].subject;
        }
    }
}

void printMenu()
{
    std::cout << '\t' << '\t' << "Menu" << std::endl;
    std::cout << "1. Enter a new Student" << std::endl;
    std::cout << "2. Print the Students born in March" << std::endl;
    std::cout << "3. Print the Student with the highest score" << std::endl;
    std::cout << "0. Exit" << std::endl;
}