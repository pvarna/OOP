#include "facultyMember.h"
#include <iostream>

FacultyMember::FacultyMember() : Person(""), Student("", 0), Lecturer("", 0)
{}

FacultyMember::FacultyMember(std::string name, unsigned int number, unsigned int salary) : Person(name), Student(name, number), Lecturer(name, salary)
{}

std::string FacultyMember::getName() const
{
    return Person::getName();
}

unsigned int FacultyMember::getNumber() const
{
    return Student::getNumber();
}

unsigned int FacultyMember::getSalary() const
{
    return Lecturer::getSalary();
}

std::istream& operator >> (std::istream& in, FacultyMember& facultyMember)
{
    std::cout << "Please enter name: ";
    getline(in, facultyMember.name);

    std::cout << "Please enter number: ";
    in >> facultyMember.number;

    std::cout << "Please enter salary: ";
    in >> facultyMember.salary;
    in.ignore();

    return in;
}

void FacultyMember::write(std::ofstream& file)
{
    if (!file.is_open())
    {
        throw std::invalid_argument("Problem while opening the file");
    }

    file << this->name << " " << this->number << " " << this->salary;
}

void FacultyMember::read(std::ifstream& file)
{
    if (!file.is_open())
    {
        throw std::invalid_argument("Problem while opening the file");
    }

    file >> this->name >> this->number >> this->salary;
}

std::ostream& operator << (std::ostream& out, const FacultyMember& facultyMember)
{
    out << "Name: " << facultyMember.name << std::endl;
    out << "Number: " << facultyMember.number << std::endl;
    out << "Salary: " << facultyMember.salary << std::endl;

    return out;
}