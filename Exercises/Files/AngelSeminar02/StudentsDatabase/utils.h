#pragma once

#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include "student.h"

const int BUFFER_LINE_SIZE = 1024;

int getCountOfLines(const char* fileName);

void readStudent(const char* line, Student& student);

bool saveStudentsToFile(const Student* studentCollection, std::size_t size, const char* fileName);

int indexOfFirstSpaceOrTerminatingZero(const char* command);

bool printStudent(const Student* studentCollection, std::size_t size,  int facultyNumber);

bool editFirstName(Student* studentCollection, std::size_t size, int facultyNumber, const char* newFirstName);
