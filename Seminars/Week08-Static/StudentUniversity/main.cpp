#include <iostream>
#include "Student.h"
#include "Subject.h"
#include "University.h"

int main ()
{
    University university;

    university.addStudent("Peter", false);
    university.addStudent("Sonya", false);
    university.addStudent("Maria", false);

    Subject math;

    math.setUniversity(&university);

    math.printStudentsWhoAreNotEnrolled();

    std::cout << std::endl;

    math.addFacultyNumber(100000);
    math.addFacultyNumber(100002);
    math.addFacultyNumber(100001);

    math.printStudentsWhoAreNotEnrolled();

    std::cout << std::endl;

    for (std::size_t i = 0; i < math.getSize(); ++i)
    {
        std::cout << math[i] << std::endl;
    }

    return 0;
}