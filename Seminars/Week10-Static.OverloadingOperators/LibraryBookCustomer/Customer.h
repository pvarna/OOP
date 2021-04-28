#pragma once

#include <iostream>
#include <cstring>

class Customer
{
private:
    static int counter;
    int id;
    unsigned int age;
    char* name;

    void copy(const Customer& other);
    void deallocate();

public:
    Customer();
    Customer(const char* name, int age);
    Customer(const Customer& other);
    Customer& operator = (const Customer& other);
    ~Customer();

    bool operator == (const Customer& other) const;
    bool operator < (const Customer& other) const;
    bool operator > (const Customer& other) const;

    int getId() const;

    friend std::ostream& operator << (std::ostream& out, const Customer& customer);
};