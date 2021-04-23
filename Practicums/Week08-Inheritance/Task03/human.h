#pragma once

#include <string>

class Human
{
protected:
    std::string name;
    std::string family;
    unsigned int age;

public:
    Human(std::string name, std::string family, unsigned int age);

    void print();
};