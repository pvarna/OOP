#pragma once

const int FIELD_MAX_SIZE = 50;

struct Student
{
    char firstName[FIELD_MAX_SIZE];
    char family[FIELD_MAX_SIZE];
    char email[FIELD_MAX_SIZE];
    unsigned int facultyNumber = 0;
};