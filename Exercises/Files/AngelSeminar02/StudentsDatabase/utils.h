#pragma once

#include <cstddef>
#include "student.h"

int getNumberOfLines(const char* fileName);

void readStudent(const char* line, Student& student);

bool saveStudentsToFile(const Student* studentCollection, std::size_t size, const char* fileName);

int indexOfFirstSpaceOrTerminatingZero(const char* command);

bool printStudent(const Student* studentCollection, std::size_t size,  int facultyNumber);

bool editFirstName(Student* studentCollection, std::size_t size, int facultyNumber, const char* newFirstName);