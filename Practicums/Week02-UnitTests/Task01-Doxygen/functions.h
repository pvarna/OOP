/**
 * \brief Structures for book and library
 * \author P. Kolev
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

const int MAX_NUMBER_BOOKS = 1000; //!< const variable showing the maximum number of books

struct Book
{
    char* title; //!< stores the title of the book
    char* author; //!< stores the name of the author of the book
    char* ISBN; //!< stores the ISBN code of the book

    //! Function for reading a book from the console
    void readBook();
};

struct Library
{
    Book books[MAX_NUMBER_BOOKS]; //!< static array that stores multiple books (library)
    int numberOfBooks = 0; //!< stores the number of the books in the library

    //! Function for adding a book into the library
    void addBook();

    //! Function for removing a book from the library
    void removeBook();

    //! Function for showing the number of books in the library
    void printNumberOfBooks();

    //! Function for deallocating the memory allocated for the library
    void deallocateMemory();
};

//! Function for printing the main menu of the program
void printMenu();

#endif