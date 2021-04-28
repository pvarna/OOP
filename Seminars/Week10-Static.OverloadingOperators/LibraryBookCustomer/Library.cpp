#include "Library.h"

Library::Library()
{
    this->customers = nullptr;
    try
    {
        this->customers = new Customer*[INITIAL_CAPACITY];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }

    this->books = nullptr;
    try
    {
        this->books = new Book*[INITIAL_CAPACITY];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        delete[] this->customers;
        exit(1);
    }
        
    this->sizeCustomers = 0;
    this->sizeBooks = 0;
    this->capacityCustomers = INITIAL_CAPACITY;
    this->capacityBooks = INITIAL_CAPACITY;
}

Library::~Library()
{
    for (std::size_t i = 0; i < this->sizeCustomers; ++i)
    {
        delete this->customers[i];
    }
    delete[] this->customers;

    for (std::size_t i = 0; i < this->sizeBooks; ++i)
    {
        delete this->books[i];
    }
    delete[] this->books;
}

void Library::resizeCustomers()
{
    Customer** buffer = nullptr;
    try
    {
        buffer = new Customer*[this->capacityCustomers * INCREASE_STEP];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    for (std::size_t i = 0; i < this->sizeCustomers; ++i)
    {
        buffer[i] = new Customer(*this->customers[i]);
    }

    for (std::size_t i = 0; i < this->sizeCustomers; ++i)
    {
        delete this->customers[i];
    }
    delete[] this->customers;
    this->customers = buffer;
    this->capacityCustomers *= INCREASE_STEP;
}

void Library::resizeBooks()
{
    Book** buffer = nullptr;
    try
    {
        buffer = new Book*[this->capacityBooks * INCREASE_STEP];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (std::size_t i = 0; i < this->sizeBooks; ++i)
    {
        buffer[i] = new Book(*this->books[i]);
    }

    for (std::size_t i = 0; i < this->sizeBooks; ++i)
    {
        delete this->books[i];
    }
    delete[] this->books;
    this->books = buffer;
    this->capacityBooks *= INCREASE_STEP;   
}

void Library::addCustomer(const char* name, unsigned int age)
{
    if (this->sizeCustomers >= this->capacityCustomers)
    {
        this->resizeCustomers();
    }

    this->customers[this->sizeCustomers++] = new Customer(name, age);
}

void Library::addBook(const char* title, unsigned int yearOfPublishing, int customerId)
{
    if (this->sizeBooks >= this->capacityBooks)
    {
        this->resizeBooks();
    }

    this->books[this->sizeBooks++] = new Book(title, yearOfPublishing, customerId);
}

void Library::takeBook(int customerId, int bookId)
{
    int searchedIndexCustomer = -1;
    for (std::size_t i = 0; i < this->sizeCustomers; ++i)
    {
        if (this->customers[i]->getId() == customerId)
        {
            searchedIndexCustomer = i;
            break;
        }
    }

    if (searchedIndexCustomer == -1)
    {
        throw std::invalid_argument("There is not a customer with such Id in the library");
    }

    int searchedIndexBook = -1;
    for (std::size_t i = 0; i < this->sizeBooks; ++i)
    {
        if (this->books[i]->getId() == bookId)
        {
            searchedIndexBook = i;
            break;
        }
    }

    if (searchedIndexBook == -1)
    {
        throw std::invalid_argument("There is not a book with such Id in the library");
    }

    if (this->books[searchedIndexBook]->getCustomerId() != -1)
    {
        throw std::invalid_argument("The book is already taken");
    }

    this->books[searchedIndexBook]->setCustomerId(customerId);   
}

void Library::returnBook(int customerId, int bookId)
{
    int searchedIndexCustomer = -1;
    for (std::size_t i = 0; i < this->sizeCustomers; ++i)
    {
        if (this->customers[i]->getId() == customerId)
        {
            searchedIndexCustomer = i;
            break;
        }
    }

    if (searchedIndexCustomer == -1)
    {
        throw std::invalid_argument("There is not a customer with such Id in the library");
    }

    int searchedIndexBook = -1;
    for (std::size_t i = 0; i < this->sizeBooks; ++i)
    {
        if (this->books[i]->getId() == bookId)
        {
            searchedIndexBook = i;
            break;
        }
    }

    if (searchedIndexBook == -1)
    {
        throw std::invalid_argument("There is not a book with such Id in the library");
    }

    if (this->books[searchedIndexBook]->getCustomerId() == -1)
    {
        throw std::invalid_argument("The book is not taken");
    }

    this->books[searchedIndexBook]->setCustomerId(-1);
}

void Library::printUntakenBooks()
{
    for (std::size_t i = 0; i < this->sizeBooks; ++i)
    {
        if (this->books[i]->getCustomerId() == -1)
        {
            std::cout << *this->books[i] << std::endl;
        }
    }
}

Customer Library::getYoungestCustomer() const
{
    Customer result = *this->customers[0];

    for (std::size_t i = 1; i < this->sizeCustomers; ++i)
    {
        if (*this->customers[i] < result)
        {
            result = *this->customers[i];
        }
    }

    return result;
}

Customer Library::getOldestCustomer() const
{
    Customer result = *this->customers[0];

    for (std::size_t i = 1; i < this->sizeCustomers; ++i)
    {
        if (*this->customers[i] > result)
        {
            result = *this->customers[i];
        }
    }

    return result;
}

Book Library::getNewestBook() const
{
    Book result = *this->books[0];

    for (std::size_t i = 1; i < this->sizeBooks; ++i)
    {
        if (*this->books[i] > result)
        {
            result = *this->books[i];
        }
    }

    return result;
}

Book Library::getOldestBook() const
{
    Book result = *this->books[0];

    for (std::size_t i = 1; i < this->sizeBooks; ++i)
    {
        if (*this->books[i] < result)
        {
            result = *this->books[i];
        }
    }

    return result;
}