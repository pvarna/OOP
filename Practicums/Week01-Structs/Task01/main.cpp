#include "functions.h"
//#include "functions.cpp"
#include <iostream>

int main ()
{
    int option;
    Library myLibrary;

    do
    {
        printMenu();

        std::cout << "Please choose an option: ";
        std::cin >> option;
        std::cin.ignore();

        system("cls");

        switch (option)
        {
            case 1:
                myLibrary.addBook();
                break;
            case 2:
                myLibrary.removeBook();
                break;
            case 3:
                myLibrary.printNumberOfBooks();
                break;
        }

    } while (option > 0);

    myLibrary.deallocateMemory();
    
    return 0;
}