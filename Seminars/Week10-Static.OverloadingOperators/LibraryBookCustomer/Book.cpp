#include "Book.h"

unsigned int Book::counter = 1000;

Book::Book()
{
    //this->id = Book::counter++;
    this->title = nullptr;
    this->yearOfPublishing = 0;
    this->customerId = -1;
}

Book::Book(const char* title, unsigned int yearOfPublishing, int customerId)
{
    this->id = Book::counter++;
    this->customerId = customerId;
    this->title = nullptr;
    try
    {
        this->title = new char[strlen(title) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
    
    strcpy(this->title, title);
    this->yearOfPublishing = yearOfPublishing;
}

void Book::copy(const Book& other)
{
    char* buffer = nullptr;
    try
    {
        buffer = new char[strlen(other.title) + 1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
    
    strcpy(buffer, other.title);
    this->id = other.id;
    this->title = buffer;
    this->customerId = other.customerId;
    this->yearOfPublishing = other.yearOfPublishing;
}

void Book::deallocate()
{
    if (this->title)
    {
        delete[] this->title;
    }
}

Book::Book(const Book& other)
{
    this->copy(other);
}

Book& Book::operator = (const Book& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

Book::~Book()
{
    this->deallocate();
}

bool Book::operator == (const Book& other) const
{
    return this->id == other.id && strcmp(this->title, other.title) == 0 
            && this->yearOfPublishing == other.yearOfPublishing;
}

bool Book::operator < (const Book& other) const
{
    return this->yearOfPublishing < other.yearOfPublishing;
}

bool Book::operator > (const Book& other) const
{
    return this->yearOfPublishing > other.yearOfPublishing;
}

std::ostream& operator << (std::ostream& out, const Book& book)
{
    out << "Id: " << book.id << std::endl;
    if (book.customerId != -1)
    {
        out << "Customer Id: " << book.customerId << std::endl;
    }
    out << "Title: " << book.title << std::endl;
    out << "Year of publishing: " << book.yearOfPublishing << std::endl;

    return out;
}

int Book::getId() const
{
    return this->id;
}

int Book::getCustomerId() const
{
    return this->customerId;
}

void Book::setCustomerId(int customerId)
{
    this->customerId = customerId;
}