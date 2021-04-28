#include "Customer.h"

int Customer::counter = 100;

Customer::Customer()
{
    //this->id = Customer::counter++;
    this->name = nullptr;
    this->age = 0;
}

Customer::Customer(const char* name, int age)
{
    this->id = Customer::counter++;
    this->name = nullptr;

    try
    {
        this->name = new char[strlen(name) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
    
    strcpy(this->name, name);
    this->age = age;
}

void Customer::copy(const Customer& other)
{
    char* buffer = nullptr;
    try
    {
        buffer = new char[strlen(other.name) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }

    strcpy(buffer, other.name);
    this->name = buffer;
    this->age = other.age;
    this->id = other.id;
}

void Customer::deallocate()
{
    if (this->name)
    {
        delete[] this->name;
    }
}

Customer::Customer(const Customer& other)
{
    this->copy(other);
}

Customer& Customer::operator = (const Customer& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

Customer::~Customer()
{
    this->deallocate();
}

bool Customer::operator == (const Customer& other) const
{
    return this->id == other.id && strcmp(this->name, other.name) == 0 && this->age == other.age;
}

bool Customer::operator < (const Customer& other) const
{
    return this->age < other.age;
}

bool Customer::operator > (const Customer& other) const
{
    return this->age > other.age;
}

std::ostream& operator << (std::ostream& out, const Customer& customer)
{
    out << "Id: " << customer.id << std::endl;
    out << "Name: " << customer.name << std::endl;
    out << "Age: " << customer.age << std::endl;

    return out;
}

int Customer::getId() const
{
    return this->id;
}