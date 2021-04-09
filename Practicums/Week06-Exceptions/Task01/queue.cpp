#include <iostream>
#include "queue.h"
#include "consts.h"

Queue::Queue()
{
    this->quantityOfTickets = 0;
    this->size = INITIAL_QUEUE_SIZE;
    try
    {
        this->tickets = new Ticket[this->size];   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

Queue::Queue(size_t size)
{
    this->quantityOfTickets = 0;
    this->size = size;
    try
    {
        this->tickets = new Ticket[this->size];   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Queue::copy(const Queue& other)
{
    this->quantityOfTickets = other.quantityOfTickets;
    this->size = other.size;
    try
    {
        this->tickets = new Ticket[this->size];   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < this->quantityOfTickets; ++i)
    {
        this->tickets[i] = other.tickets[i];
    }
}

void Queue::deallocate()
{
    if (this->tickets)
    {
        delete[] this->tickets;
    }

    this->quantityOfTickets = 0;
    this->size = 0;
}

Queue::Queue(const Queue& other)
{
    this->copy(other);
}

Queue& Queue::operator = (const Queue& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
} 
Queue::~Queue()
{
    this->deallocate();
}

int Queue::getTicket(const char* name, const char* phone, const int uniqueNumber)
{
    try
    {
        if (this->quantityOfTickets == this->size)
        {
            throw std::overflow_error("Full queue!");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Ticket ticket(name, phone, uniqueNumber);

    this->tickets[this->quantityOfTickets++] = ticket;

    return this->quantityOfTickets - 1;    
}

Ticket& Queue::operator [] (size_t index)
{
    try
    {
        if (index >= this->quantityOfTickets)
        {
            throw std::invalid_argument("No such index");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return tickets[index];   
}

Ticket Queue::next()
{
    try
    {
        if (this->quantityOfTickets == 0)
        {
            throw std::out_of_range("Empty queue");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Ticket result;
    result = this->tickets[0];

    for (int i = 0; i < this->quantityOfTickets - 1; ++i)
    {
        this->tickets[i] = this->tickets[i+1];
    }

    --this->quantityOfTickets;

    return result;   
}

bool Queue::empty() const
{
    return this->quantityOfTickets == 0;
}

int Queue::getSize() const
{
    return this->quantityOfTickets;
}