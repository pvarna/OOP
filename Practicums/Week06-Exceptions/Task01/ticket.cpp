#include <iostream>
#include <cstring>  
#include "ticket.h"
#include "helpers.h"
#include "consts.h"

void Ticket::copy(const Ticket& other)
{
    try
    {
        validateName(other.nameCustomer); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->nameCustomer = new char[strlen(other.nameCustomer) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    strcpy (this->nameCustomer, other.nameCustomer);
    

    try
    {
        validatePhone(other.phoneCustomer);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->phoneCustomer = new char[strlen(other.phoneCustomer) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    strcpy (this->phoneCustomer, other.phoneCustomer);

    this->uniqueNumber = other.uniqueNumber;
}

void Ticket::deallocate()
{
    if (this->nameCustomer)
    {
        delete[] this->nameCustomer;
    }

    if (this->phoneCustomer)
    {
        delete[] this->phoneCustomer;
    }

    this->nameCustomer = nullptr;
    this->phoneCustomer = nullptr;
    this->uniqueNumber = 0;
}

void Ticket::validateName (const char* name)
{
    for (int i = 0; i < strlen(name); ++i)
    {
        if (!isLetter(name[i]))
        {
            throw std::invalid_argument("Invalid name");
        }
    }
}

void Ticket::validatePhone (const char* phone)
{
    if (strlen(phone) != 10)
    {
        throw std::length_error("Inavlid length of the phone number");
    } 
}

Ticket::Ticket()
{
    this->nameCustomer = nullptr;
    this->phoneCustomer = nullptr;
    this->uniqueNumber = 0;
}

Ticket::Ticket(const char* nameCustomer, const char* phoneCustomer, const int uniqueNumber)
{
    try
    {
        validateName(nameCustomer); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->nameCustomer = new char[strlen(nameCustomer) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    strcpy (this->nameCustomer, nameCustomer);
    

    try
    {
        validatePhone(phoneCustomer);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->phoneCustomer = new char[strlen(phoneCustomer) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    strcpy (this->phoneCustomer, phoneCustomer);

    this->uniqueNumber = uniqueNumber;
}

Ticket::Ticket(const Ticket& other)
{
    this->copy(other);
}

Ticket& Ticket::operator = (const Ticket& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

Ticket::~Ticket()
{
    this->deallocate();
}

char* Ticket::getNameCustomer()
{
    return this->nameCustomer;
}

char* Ticket::getPhoneCustomer()
{
    return this->phoneCustomer;
}

int Ticket::getUniqueNumber()
{
    return this->uniqueNumber;
}

void Ticket::setNameCustomer(const char* nameCustomer)
{
    if (this->nameCustomer)
    {
        delete[] this->nameCustomer;
    }

    try
    {
        validateName(nameCustomer); 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->nameCustomer = new char[strlen(nameCustomer) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    strcpy(this->nameCustomer, nameCustomer);
}

void Ticket::setPhoneCustomer(const char* phoneCustomer)
{
    if (this->phoneCustomer)
    {
        delete[] this->phoneCustomer;
    }

    try
    {
        validatePhone(phoneCustomer);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        this->phoneCustomer = new char[strlen(phoneCustomer) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    strcpy (this->phoneCustomer, phoneCustomer);
}

void Ticket::setUniqueNumber(const int uniqueNumber)
{
    this->uniqueNumber = uniqueNumber;
}

std::ostream& operator << (std::ostream& out, const Ticket& ticket)
{
    out << "Name of customer: " << ticket.nameCustomer << std::endl;
    out << "Phone of customer: " << ticket.phoneCustomer << std::endl;
    out << "Unique number: " << ticket.uniqueNumber;

    return out;
}

std::istream& operator >> (std::istream& in, Ticket& ticket)
{
    ticket.deallocate();

    char buffer[MAX_BUFFER_SIZE];
    std::cout << "Please enter the name of the customer: ";
    in.getline(buffer, MAX_BUFFER_SIZE);

    try
    {
        ticket.validateName(buffer);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        ticket.nameCustomer = new char[strlen(buffer) + 1];    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    strcpy(ticket.nameCustomer, buffer);

    std::cout << "Please enter the phone number of the customer: ";
    in.getline(buffer, MAX_BUFFER_SIZE);

    try
    {
        ticket.validateName(buffer);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        ticket.phoneCustomer = new char[strlen(buffer) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    strcpy(ticket.phoneCustomer, buffer);

    std::cout << "Please enter the unique number of the customer: ";
    in >> ticket.uniqueNumber;
    in.ignore();

    return in;
}