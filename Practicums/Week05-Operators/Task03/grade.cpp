#include "grade.h"
#include <iostream>
#include <cstring>

void Grade::input()
{
    char buffer[100];

    std::cout << "Please enter the name of the subject: ";
    std::cin.getline(buffer, 100);

    size_t size = strlen(buffer);
    this->subjectName = new(std::nothrow) char[size+1];
    if (!subjectName)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(this->subjectName, buffer);
    this->subjectName[size] = '\0';

    std::cout << "Please enter the grade (2-6): ";
    std::cin >> this->grade; 
    std::cin.ignore();
}