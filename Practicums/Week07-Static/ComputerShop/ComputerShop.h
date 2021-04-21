#pragma once

#include <string>
#include "Computer.h"

typedef bool (*filterFunction) (const Computer& computer);

class ComputerShop
{
private:
    std::string name;
    Computer* computers;
    std::size_t size;
    std::size_t currentCount;

public:
    ComputerShop(std::string name, std::size_t size);
    ComputerShop(const ComputerShop& other) = delete;
    ComputerShop& operator = (const ComputerShop& other) = delete;
    ~ComputerShop();

    void addComputer(const Computer& computer);
    void buyComputer(double moneyOnHand, std::string wantedBrand);

    friend std::ostream& operator << (std::ostream& out, const ComputerShop& computerShop);

    Computer* filter(filterFunction func, std::size_t& resultSize);
};