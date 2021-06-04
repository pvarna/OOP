#pragma once

#include <cstddef>

class Furniture
{
protected:
    static unsigned int counter;
    unsigned int id;
    double height;
    double width;
    double length;
    std::size_t quantity;
    double price;

    Furniture(double height, double width, double length, std::size_t quantity, double price);

public:
    unsigned int getId() const;
    std::size_t getQuantity() const;
    void increaseQuantityBy(unsigned int by);
    void reduceQuantityBy(unsigned int by);

    virtual void print();
};