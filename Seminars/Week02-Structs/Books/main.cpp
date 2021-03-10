#include "book.h"
#include "library.h"
#include "utils.h"
#include <iostream>

int main ()
{
    Library myLibrary;

    myLibrary.initialize(4);

    myLibrary.addBook();
    myLibrary.addBook();
    myLibrary.addBook();

    myLibrary.printBooks();

    std::cout << std::endl;

    Book bestBook = myLibrary.getBestBook();
    std::cout << "Book with most sales:" << std::endl;
    bestBook.printInformation();

    std::cout << std::endl;

    std::cout << "Book with lowest price:" << std::endl;
    myLibrary.printBookByPrice(isCheaper);

    std::cout << std::endl;

    std::cout << "Book with highest price:" << std::endl;
    myLibrary.printBookByPrice(isMoreExpensive);

    myLibrary.deallocateMemory();

    return 0;
}