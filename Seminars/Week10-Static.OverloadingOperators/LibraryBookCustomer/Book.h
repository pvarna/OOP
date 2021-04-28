#pragma once
/*
Задача 2:
Напишете клас Book, който има следните данни:

- id(идентификационен номер на кредита);
- id на клиента, който наема книгата;
- заглавие;
- година на издаване.
Нека притежава следните функционалности:

- Класа да се създава с конструктор с параметри, но без id. То трябва да се генерира последователно за всяка следваща книга като започва от 1. 
- Да предефинира operator==, operator< и operator>. Операторите за сравнение да сравняват две книги спрямо годината им на издаване.
- Метод, който принтира всички данни на книгата.
*/

#include <iostream>
#include <cstring>

class Book
{
private:
    static unsigned int counter;
    unsigned int id;
    int customerId;
    char* title;
    unsigned int yearOfPublishing;

    void copy(const Book& other);
    void deallocate();

public:
    Book();
    Book(const char* title, unsigned int yearOfPublishing, int customerId);
    Book(const Book& other);
    Book& operator = (const Book& other);
    ~Book();

    bool operator == (const Book& other) const;
    bool operator < (const Book& other) const;
    bool operator > (const Book& other) const;

    friend std::ostream& operator << (std::ostream& out, const Book& book);

    int getId() const;
    int getCustomerId() const;

    void setCustomerId(int customerId);
};