#pragma once
/*
Задача 3:
Напишете клас Library, който съдържа масив от Customer и масив от Book.

Нека притежава следните функционалности:

- метод, който добавя(създава) клиент, чиито данни ще са подадени като парaмeтри на метода;
- метод, който добавя(създава) книга, чиито данни ще са подадени като парaмeтри на метода. 
- метод, при който клиент наема книга (подават се id на клиента, който наема книга и id на книгата, която се наема);
- метод, при който клиент връща книга (подават се id на клиента, който връща книга и id на книгата, която се връща);
- метод, който принтира всички ненаети книги;
- метод, който намира най-младия клиент;
- метод, който намира най-стария клиент;
- метод, който намира книгата, издадена най-скоро;
- метод, който намира книгата, издадена най-отдавна;
*/

#include <iostream>
#include <cstring>
#include <cstddef>
#include "Customer.h"
#include "Book.h"

const int INITIAL_CAPACITY = 2;
const int INCREASE_STEP = 2;

class Library
{
private:
    Customer** customers;
    Book** books;
    std::size_t sizeCustomers;
    std::size_t capacityCustomers;
    std::size_t sizeBooks;
    std::size_t capacityBooks;

    void resizeCustomers();
    void resizeBooks();

public:
    Library();
    Library(const Library& other) = delete;
    Library& operator = (const Library& other) = delete;
    ~Library();

    void addCustomer(const char* name, unsigned int age);
    void addBook(const char* title, unsigned int yearOfPublishing, int customerId);

    void takeBook(int customerId, int bookId);
    void returnBook(int customerId, int bookId);

    void printUntakenBooks();

    Customer getYoungestCustomer() const;
    Customer getOldestCustomer() const;

    Book getNewestBook() const;
    Book getOldestBook() const;
};