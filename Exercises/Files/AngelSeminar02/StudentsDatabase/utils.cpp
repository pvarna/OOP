#include <iostream>
#include <fstream>
#include <cstring>
#include "utils.h"

int getNumberOfLines(const char* fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        return -1;
    }

    int counter = 0;
    while (!file.eof())
    {
        std::string temp;
        getline(file, temp);
        ++counter;
    }

    file.close();

    return counter;    
}

// firstName, Family, email, fn
void readStudent(const char* line, Student& student)
{
    int index = 0;

    // first name
    while (line[index] != ',')
    {
        student.firstName[index] = line[index];
        ++index;
    }
    student.firstName[index] = '\0';
    ++index;

    // family
    int familyIndex = 0;
    while (line[index] != ',')
    {
        student.family[familyIndex++] = line[index++];
    }
    student.family[familyIndex] = '\0';
    ++index;

    // email
    int emailIndex = 0;
    while (line[index] != ',')
    {
        student.email[emailIndex++] = line[index++];
    }
    student.email[emailIndex] = '\0';
    +index;

    // fn
    while (line[index] != '\0')
    {
        student.facultyNumber *= 10;
        student.facultyNumber += (line[index++] - '0');
    }

}

bool saveStudentsToFile(const Student* studentCollection, std::size_t size, const char* fileName)
{
    std::ofstream file(fileName);

    if (!file.is_open())
    {
        return false;
    }

    file << "First name, Family, E-mail, Faculty number" << std::endl;

    for (std::size_t i = 0; i < size; ++i)
    {
        file << studentCollection[i].firstName << "," << studentCollection[i].family << "," << studentCollection[i].email << "," << studentCollection[i].facultyNumber << std::endl;
    }

    file.close();

    return true;
}

int indexOfFirstSpaceOrTerminatingZero(const char* command)
{
	int index = 0;

	while (*command != ' ' && *command != '\t' && *command != '\0')
	{
		++index;
        ++command;
	}

	return index;
}

bool printStudent(const Student* studentCollection, std::size_t size,  int facultyNumber)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        if (studentCollection[i].facultyNumber == facultyNumber)
        {
            std::cout << studentCollection[i].firstName << "," << studentCollection[i].family << "," << studentCollection[i].email << "," << studentCollection[i].facultyNumber << std::endl;
            return true;
        }
    }

    return false;
}

bool editFirstName(Student* studentCollection, std::size_t size, int facultyNumber, const char* newFirstName)
{
    for (std::size_t i = 0; i < size; i++)
	{
		if (studentCollection[i].facultyNumber == facultyNumber)
		{
			strcpy(studentCollection[i].firstName, newFirstName);
			return true;
		}
	}

	return false;
}