#pragma once

struct Book
{
    char* title;
    char* author;
    char* genre;
    double price;
    int numberOfSales;
    double readersRating;

    void initialize();
    void deallocateMemory();
    void printInformation();
};
