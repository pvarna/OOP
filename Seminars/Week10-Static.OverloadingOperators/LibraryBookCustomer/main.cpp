#include <iostream>
#include "Library.h"

int main ()
{
    Library myLibrary;

    myLibrary.addCustomer("Pesho", 19);
    myLibrary.addCustomer("Tsveti", 20);
    myLibrary.addCustomer("Gosho", 21);

    myLibrary.addBook("Harry Potter", 2000, -1);
    myLibrary.addBook("Pod igoto", 1980, -1);
    myLibrary.addBook("OOP", 2010, -1);

    //myLibrary.printUntakenBooks();

    myLibrary.takeBook(100, 1000);

    //myLibrary.printUntakenBooks();
    
    myLibrary.returnBook(100, 1000);

    //myLibrary.printUntakenBooks();

    std::cout << myLibrary.getOldestCustomer() << std::endl;
    std::cout << myLibrary.getYoungestCustomer() << std::endl;
    std::cout << myLibrary.getNewestBook() << std::endl;
    std::cout << myLibrary.getOldestBook() << std::endl;

    return 0;
}