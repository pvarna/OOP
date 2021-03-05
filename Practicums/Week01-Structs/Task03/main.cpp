#include "functions.h"
#include <iostream>

int main ()
{
    Students students;
    int option;

    do
    {
        printMenu();

        std::cin >> option;
        std::cin.ignore();

        system("cls");

        switch (option)
        {
            case 1:
                students.addStudent();
                break;
            case 2:
                students.printStudentsBornInMarch();
                break;
            case 3:
                students.printStudentWithHighestScore();
                break;
        }

    } while (option);
    
    students.deallocateMemory();

    return 0;
}