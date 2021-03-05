#include "functions.h"
#include <iostream>
#include <cstring>

void Book::readBook()
{
    char buffer[1000];
    size_t size;

    std::cout << "Please enter the title of the book: ";
    std::cin.getline(buffer, 1000);
    size = strlen(buffer);
    title = new(std::nothrow) char[size];
    strcpy(title, buffer);

    std::cout << "Please enter the author of the book: ";
    std::cin.getline(buffer, 1000);
    size = strlen(buffer);
    author = new(std::nothrow) char[size];
    strcpy(author, buffer);

    std::cout << "Please enter the ISBN of the book: ";
    std::cin >> buffer;
    std::cin.ignore();
    size = strlen(buffer);
    ISBN = new(std::nothrow) char[size];
    strcpy(ISBN, buffer);
}

void Library::addBook()
{
    Book newBook;
    newBook.readBook();

    books[numberOfBooks++] = newBook;

    std::cout << "The book has been added successfully" << std::endl << std::endl;
}

void Library::removeBook()
{
    char searchedISBN[13];

    std::cout << "Please enter the ISBN of the book you want to remove: ";
    std::cin >> searchedISBN;
    std::cin.ignore();

    int index = -1;
    for (int i = 0; i < numberOfBooks; ++i)
    {
        if (strcmp(searchedISBN, books[i].ISBN) == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        std::cout << "There is no such book" << std::endl << std::endl;
    }

    else
    {
        for (int i = index; i < numberOfBooks-1; ++i)
        {
            books[i] = books[i+1];
        }
        --numberOfBooks;

        std::cout << "The book has been removed successfully" << std::endl << std::endl;
    }
}

void Library::printNumberOfBooks()
{
    std::cout << "The current number of the books is: " << numberOfBooks << std::endl << std::endl;
}

void Library::deallocateMemory()
{
    for (int i = 0; i < numberOfBooks; ++i)
    {
        delete[] books[i].title;
        delete[] books[i].author;
        delete[] books[i].ISBN;
    }
}

void printMenu()
{
    std::cout << '\t' << '\t' << "Menu" << std::endl;
    std::cout << "1. Add a book to the Library" << std::endl;
    std::cout << "2. Remove a book from the Library" << std::endl;
    std::cout << "3. Get the number of books in the Library" << std::endl;
    std::cout << "0. Exit" << std::endl;
}