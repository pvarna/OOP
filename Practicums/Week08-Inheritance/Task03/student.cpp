#include <iostream>
#include "student.h"

unsigned int Student::counter = 80000;

Student::Student(std::string name, std::string family, unsigned int age, std::string specialty) : Human(name, family, age)
{
    this->facultyNumber = counter++;
    this->specialty = specialty;
}

void Student::print()
{
    Human::print();
    std::cout << "Faculty number: " << this->facultyNumber << std::endl;
    std::cout << "Specialty: " << this->specialty << std::endl;
}