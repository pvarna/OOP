#pragma once

#include "ticket.h"

class Queue
{
private:
    Ticket* tickets;
    size_t quantityOfTickets;
    size_t size;

    void copy(const Queue& other);
    void clear();
    void deallocate();
    
public:
    Queue();
    Queue(size_t size);
    Queue(const Queue& other); 
    ~Queue();

    int getTicket(const char* name, const char* phone, const int uniqueNumber);
    Ticket& operator [] (size_t index);

    Ticket next();
    bool empty() const;
    int getSize() const;

    Queue& operator = (const Queue& other);
};