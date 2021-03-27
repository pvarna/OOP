#include <iostream>
#include <cstring>
#include "horo.h"

Horo::Horo(const char* name, const char* tact, const Region region)
{
    this->name = new(std::nothrow) char[strlen(name) + 1];
    strcpy(this->name, name);

    this->tact = new(std::nothrow) char[strlen(tact) + 1];
    strcpy(this->tact, tact);

    this->region = region;
}

void Horo::print()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Tact: " << this->tact << std::endl;
    std::cout << "Region: ";
    switch (region)
    {
    case 0:
        std::cout << "Severnyashki" << std::endl;
        break;
    case 1:
        std::cout << "Dobrudzhanski" << std::endl;
        break;
    case 2:
        std::cout << "Strandzhanski" << std::endl;
        break;
    case 3:
        std::cout << "Trakiiski" << std::endl;
        break;
    case 4:
        std::cout << "Rodopski" << std::endl;
        break;
    case 5:
        std::cout << "Pirinski" << std::endl;
        break;
    case 6:
        std::cout << "Shopski" << std::endl;
        break;
    }
}

char* Horo::getName() const
{
    return this->name;
}

char* Horo::getTact() const
{
    return this->tact;
}

Region Horo::getRegion() const
{
    return this->region;
}

Horo::~Horo()
{
    delete[] this->name;
    delete[] this->tact;
}