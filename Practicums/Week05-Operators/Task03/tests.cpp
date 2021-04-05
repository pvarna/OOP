#define CATCH_CONFIG_MAIN
#include "..\..\..\catch2\catch2.hpp"
#include "university.h"

TEST_CASE ("operator +=")
{
    size_t numberStudents = 3;
    Student* myStudents = new Student[3];
    Student student1("Peter Kolev", "014611XXXX", "82214", 6, 5, 5, 6, 4);
    Student student2("Sonya Nikolova", "015027XXXX", "82213", 5, 6, 5, 5, 6);
    Student student3("Mihail Enev", "014611XXXX", "7....", 6, 5, 6, 5, 6);

    myStudents[0] = student1;
    myStudents[1] = student2;
    myStudents[2] = student3;

    University university1;
    
    university1.createStudents(myStudents, numberStudents);

    SECTION ("initialization check")
    {
        REQUIRE (university1.getCapacity() == 13);
        REQUIRE (university1.getSize() == 3);
    }

    Student temp("Temp Temp", "01XXXXXXXX", "6....", 6, 5, 4, 3, 2);

    university1 += temp;
    SECTION ("adding a student")
    {
        REQUIRE (university1.getCapacity() == 13);
        REQUIRE (university1.getSize() == 4);
    }

    university1 += temp;

    SECTION ("trying to add a student who is already in the university")
    {
        REQUIRE (university1.getCapacity() == 13);
        REQUIRE (university1.getSize() == 4);
    }

    university1 -= temp;

    SECTION ("removing a student")
    {
        REQUIRE (university1.getCapacity() == 13);
        REQUIRE (university1.getSize() == 3);
    }

    university1 -= temp;

    SECTION ("trying to remove a student who isn't in the university")
    {
        REQUIRE (university1.getCapacity() == 13);
        REQUIRE (university1.getSize() == 3);
    }

    Student mime("Maria Radostinova", "015111XXXX", "82208", 6, 5, 6, 5, 6);
    university1 += mime;

    SECTION ("check operator[]")
    {
        REQUIRE (university1.getCapacity() == 13);
        REQUIRE (university1.getSize() == 4);
        REQUIRE (university1[university1.getSize() - 1] == mime);
    }
}