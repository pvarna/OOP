#include <iostream>
#include "university.h"

int main ()
{
    University university1, university2;

    university1.addStudent("Peter", 82214, true);
    university1.addStudent("Sonya", 82213, true);
    university1.addStudent("Maria", 82208, false);

    university2.addStudent("Mihail", 72490, true);
    university2.addStudent("Alkan", 72500, false);

    University university;
    university = university1 + university2;

    for (int i = 0; i < university.getSize(); ++i)
    {
        std::cout << university[i] << std::endl;
    }
    return 0;
}