#pragma once

const int MAX_NUMBER_BOOKS = 1000;

struct Book
{
    char* title;
    char* author;
    char* ISBN;

    void readBook();
};

struct Library
{
    Book books[MAX_NUMBER_BOOKS];
    int numberOfBooks = 0;

    void addBook();
    void removeBook();
    void printNumberOfBooks();
    void deallocateMemory();
};

void printMenu();