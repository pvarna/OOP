#include <iostream>
#include "ComputerShop.h"

ComputerShop::ComputerShop(std::string name, std::size_t size)
{
    this->name = name;
    this->computers = new Computer[size];
    this->size = size;
    this->currentCount = 0;
}

ComputerShop::~ComputerShop()
{
    if (this->computers)
    {
        delete[] this->computers;
    }
}

void ComputerShop::addComputer(const Computer& computer)
{
    if (this->currentCount == this->size)
    {
        throw std::overflow_error("No more space for computers");
    }

    for (std::size_t i = 0; i < this->currentCount; ++i)
    {
        if (this->computers[i].getBrand() == computer.getBrand())
        {
            this->computers[i].increaseQuantity();
            return;
        }
    }

    this->computers[this->currentCount++] = computer;
}

std::ostream& operator << (std::ostream& out, const ComputerShop& computerShop)
{
    for (std::size_t i = 0; i < computerShop.currentCount; ++i)
    {
        out << "ComputerType #" << i+1 << ":" << std::endl;
        out << computerShop.computers[i] << std::endl;
    }

    return out;
}

void ComputerShop::buyComputer(double moneyOnHand, std::string wantedBrand)
{
    for (std::size_t i = 0; i < this->currentCount; ++i)
    {
        if (this->computers[i].getBrand() == wantedBrand)
        {
            if (this->computers[i].getPrice() > moneyOnHand)
            {
                throw std::invalid_argument("Not enough money");
            }
            else
            {
                this->computers[i].decreaseQuantity();
                std::cout << "Successfull purchase" << std::endl;
            }

            if (this->computers[i].getQuantity() == 0)
            {
                std::swap(this->computers[i], this->computers[this->currentCount - 1]);
                --this->currentCount;
            }

            return;
        }
    }

    throw std::invalid_argument("Not such brand in the shop");
}

Computer* ComputerShop::filter(filterFunction func, std::size_t& resultSize)
{
    resultSize = 0;
    for (std::size_t i = 0; i < this->currentCount; ++i)
    {
        if (func(this->computers[i]))
        {
            ++resultSize;
        }
    }

    Computer* result = new Computer[resultSize];

    std::size_t counter = 0;
    for (std::size_t i = 0; i < this->currentCount; ++i)
    {
        if (func(this->computers[i]))
        {
            result[counter++] = this->computers[i];
        }
    }

    return result;
}