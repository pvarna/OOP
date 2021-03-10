#include "book.h"
#include <iostream>
#include <cstring>

void Book::initialize()
{
    char buffer[100];
    size_t size;

    std::cout << "Please enter the title of the book: ";
    std::cin.getline(buffer, 100);
    size = strlen(buffer);
    title = new(std::nothrow) char[size+1];
    if (!title)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(title, buffer);
    title[size] = '\0';

    std::cout << "Please enter the author of the book: ";
    std::cin.getline(buffer, 100);
    size = strlen(buffer);
    author = new(std::nothrow) char[size+1];
    if (!author)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(author, buffer);
    author[size] = '\0';

    std::cout << "Please enter the genre of the book: ";
    std::cin.getline(buffer, 100);
    size = strlen(buffer);
    genre = new(std::nothrow) char[size+1];
    if (!genre)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(genre, buffer);
    genre[size] = '\0';

    std::cout << "Please enter the price of the book (BGN): ";
    std::cin >> price;

    std::cout << "Please enter the number of sales of the book: ";
    std::cin >> numberOfSales;

    std::cout << "Please enter the rating of the book according to the readers (0-10): ";
    std::cin >> readersRating;
    std::cin.ignore();
}

void Book::deallocateMemory()
{
    delete[] title;
    delete[] author;
    delete[] genre;
}

void Book::printInformation()
{
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Genre: " << genre << std::endl;
    std::cout << "Price: " << price << " BGN" << std::endl;
    std::cout << "Number of sales: " << numberOfSales << std::endl;
    std::cout << "Rating: " << readersRating << "/10" << std::endl;
}