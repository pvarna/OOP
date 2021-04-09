#pragma once

class Ticket
{
private:
    char* nameCustomer;
    char* phoneCustomer;
    int uniqueNumber;

    void copy(const Ticket& other);
    void deallocate();

    void validateName (const char* name);
    void validatePhone (const char* phone);

public:
    Ticket();
    Ticket(const char* nameCustomer, const char* phoneCustomer, const int uniqueNumber);
    Ticket(const Ticket& other);
    ~Ticket();

    char* getNameCustomer();
    char* getPhoneCustomer();
    int getUniqueNumber();

    void setNameCustomer(const char* nameCustomer);
    void setPhoneCustomer(const char* phoneCustomer);
    void setUniqueNumber(const int uniqueNumber);

    Ticket& operator = (const Ticket& other);

    friend std::ostream& operator << (std::ostream& out, const Ticket& ticket);
    friend std::istream& operator >> (std::istream& in, Ticket& ticket);
};