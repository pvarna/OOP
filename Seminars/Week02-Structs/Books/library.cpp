#include "book.h"
#include "library.h"
#include <iostream>

void Library::initialize(int capacity)
{
    library = new(std::nothrow) Book[capacity];
    if (!library)
    {
        std::cout << "Memory problem" << std::endl;
        return;
    }

    capacityLibrary = capacity;
    sizeLibrary = 0;

    std::cout << "Library created successfully!" << std::endl;
}

void Library::resize()
{
    Book* old = library;

    capacityLibrary *= 2;

    library = new(std::nothrow) Book[capacityLibrary];
    if (!library)
    {
        std::cout << "Memory problem" << std::endl;
        return;
    }

    for (int i = 0; i < sizeLibrary; ++i)
    {
        library[i] = old[i];
    }

    delete[] old;
}

void Library::deallocateMemory()
{
    for (int i = 0; i < sizeLibrary; ++i)
    {
        library[i].deallocateMemory();
    }
    delete[] library;
}

void Library::addBook()
{
    Book newBook;
    newBook.initialize();

    if (sizeLibrary == capacityLibrary)
    {
        resize();
    }

    library[sizeLibrary] = newBook;
    ++sizeLibrary;
}

void Library::printBooks()
{
    for (int i = 0; i < sizeLibrary; ++i)
    {
        std::cout << "Book #" << i+1 << std::endl;
        library[i].printInformation();
    }
}

Book& Library::getBestBook()
{
    int bestBookSales = library[0].numberOfSales;
    int bestIndex = 0;

    for (int i = 1; i < sizeLibrary; ++i)
    {
        if (library[i].numberOfSales > bestBookSales)
        {
            bestBookSales = library[i].numberOfSales;
            bestIndex = i;
        }
    }

    return library[bestIndex];
}

void Library::printBookByPrice(priceFilter fn)
{
    double bestBookPrice = library[0].price;
    int bestIndex = 0;

    for (int i = 1; i < sizeLibrary; ++i)
    {
        if (fn(library[i].price, bestBookPrice))
        {
            bestBookPrice = library[i].price;
            bestIndex = i;
        }
    }

    library[bestIndex].printInformation();
}