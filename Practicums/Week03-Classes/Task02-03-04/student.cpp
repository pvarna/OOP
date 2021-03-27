#include <iostream>
#include <cstring>
#include "student.h"

Student::Student()
{
    this->name = nullptr;
    this->facultyNumber[0] = '\0';
    this->grades[0].grade = 2;
    this->grades[1].grade = 2;
    this->grades[2].grade = 2;
    this->grades[3].grade = 2;
    this->grades[4].grade = 2;
}
Student::Student(const char* name, const char* EGN, const char* FN, 
            double grade1, double grade2, double grade3, double grade4, double grade5)
{
    size_t size = strlen(name);
    this->name = new char[size + 1];
    strcpy(this->name, name);
    
    strcpy(this->facultyNumber, FN);

    strcpy(this->EGN, EGN);

    this->grades[0].grade = grade1;
    this->grades[1].grade = grade2;
    this->grades[2].grade = grade3;
    this->grades[3].grade = grade4;
    this->grades[4].grade = grade5;
}

Student::~Student()
{
    deallocateMemory();
}

void Student::input()
{
    char buffer[100];

    std::cout << "Please enter the name of the student: ";
    std::cin.getline(buffer, 100);

    size_t size = strlen(buffer);
    this->name = new(std::nothrow) char[size + 1];
    if (!this->name)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(this->name, buffer);
    this->name[size] = '\0';

    std::cout << "Please enter the EGN of the student: ";
    std::cin >> this->EGN;
    this->EGN[10] = '\0';

    std::cout << "Please enter the faculty number of the student: ";
    std::cin >> this->facultyNumber;
    this->facultyNumber[6] = '\0';
    std::cin.ignore();

    std::cout << "Please enter the grades of the students: " << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Grade #" << i + 1 << ": " << std::endl;
        this->grades[i].input();
    }
}

double Student::getAverageGrade()
{
    double sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        sum += this->grades[i].grade;
    }

    return sum / 5;
}

void Student::print()
{
    /*std::cout << "Name: " << this->name << std::endl;
    std::cout << "EGN: " << this->EGN << std::endl;
    std::cout << "Faculty number: " << this->facultyNumber << std::endl;
    std::cout << "Average grade: " << getAverageGrade() << std::endl;*/

    std::cout << this->name << ", " << this->EGN << ", " << this->facultyNumber << ", " << getAverageGrade() << std::endl;
}

void Student::printFNAndGrades()
{
    std::cout << "Faculty number: " << this->facultyNumber << std::endl;
    std::cout << "Grades: " << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        std::cout << this->grades[i].subjectName << " - " << this->grades[i].grade << std::endl;
    }
}

void Student::deallocateMemory()
{
    delete[] this->name;
    for (int i = 0; i < 5; ++i)
    {
        delete[] this->grades[i].subjectName;
    }
}

void Student::copyStudent(Student& student)
{
    student.setName(this->name);
    student.setEGN(this->EGN);
    student.setFacultyNumber(this->facultyNumber);
    student.setGrades(this->grades);
}

char* Student::getName()
{
    return this->name;
}

char* Student::getFN()
{
    return this->facultyNumber;
}

void Student::setName(const char* wantedName)
{
    size_t size = strlen(wantedName);
    this->name = new(std::nothrow) char[size + 1];
    if (!this->name)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(this->name, wantedName);
    this->name[size] = '\0';
}

void Student::setEGN(const char* wantedEGN)
{
    strcpy(this->EGN, wantedEGN);
    this->EGN[strlen(wantedEGN)] = '\0';
}

void Student::setFacultyNumber(const char* wantedFN)
{
    strcpy(this->facultyNumber, wantedFN);
    this->facultyNumber[strlen(wantedFN)] = '\0';
}

void Student::setGrades(Grade* wantedGrades)
{
    for (int i = 0; i < 5; ++i)
    {
        size_t size = strlen(wantedGrades[i].subjectName);
        this->grades[i].subjectName = new(std::nothrow) char[size + 1];
        if (!this->grades[i].subjectName)
        {
            std::cout << "Memory problem!" << std::endl;
            return;
        }
        strcpy(this->grades[i].subjectName, wantedGrades[i].subjectName);
        this->grades[i].subjectName[size] = '\0';
        
        this->grades[i].grade = wantedGrades[i].grade;
    }
}