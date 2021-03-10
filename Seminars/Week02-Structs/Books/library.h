#pragma once
#include "book.h"
#include "utils.h"

struct Library
{
    Book* library;
    int capacityLibrary;
    int sizeLibrary;

    void initialize(int capacity);
    void resize();
    void deallocateMemory();

    void addBook();
    void printBooks();
    Book& getBestBook();

    void printBookByPrice(priceFilter fn);
};