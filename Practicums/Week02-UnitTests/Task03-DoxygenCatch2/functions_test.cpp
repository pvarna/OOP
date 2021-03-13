#define CATCH_CINFIG_MAIN
#include "..\catch2\catch2.hpp"
#include "functions.h"
#include <cmath>

TEST_CASE("Average score", "[grades]")
{
    Student student;

    SECTION("test #1")
    {
        student.grades[0].grade = 5;
        student.grades[1].grade = 4;
        student.grades[2].grade = 6;
        student.grades[3].grade = 5;
        student.grades[4].grade = 6;

        REQUIRE(student.averageScore() == 5.20);
    }

    SECTION("test #2")
    {
        student.grades[0].grade = 3;
        student.grades[1].grade = 4;
        student.grades[2].grade = 3;
        student.grades[3].grade = 5;
        student.grades[4].grade = 4;

        REQUIRE(student.averageScore() == 3.80);
    }
}

TEST_CASE("First and last name", "[student's name]")
{
    Student student;
    student.name[0] = 'P';
    student.name[1] = 'e';
    student.name[2] = 't';
    student.name[3] = 'e';
    student.name[4] = 'r';
    student.name[5] = ' ';
    student.name[6] = 'S';
    student.name[7] = 't';
    student.name[8] = 'a';
    student.name[9] = 'n';
    student.name[10] = 'o';
    student.name[11] = 'm';
    student.name[12] = 'i';
    student.name[13] = 'r';
    student.name[14] = 'o';
    student.name[15] = 'v';
    student.name[16] = ' ';
    student.name[17] = 'K';
    student.name[18] = 'o';
    student.name[19] = 'l';
    student.name[20] = 'e';
    student.name[21] = 'v';

    SECTION("test")
    {
        REQUIRE(strcmp("Peter Kolev", student.firstLastName()) == 0);       
    }
}

TEST_CASE("Capitalising letters", "[letters]")
{
    char ch;

    SECTION("test #1")
    {
        ch = 'a';

        REQUIRE(toUpper(ch) == 'A');
    }

        SECTION("test #2")
    {
        ch = 'A';

        REQUIRE(toUpper(ch) == 'A');
    }

        SECTION("test #1")
    {
        ch = '/';

        REQUIRE(toUpper(ch) == '/');
    }
}