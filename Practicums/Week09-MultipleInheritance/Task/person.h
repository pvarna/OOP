#pragma once

#include <string>

class Person
{
protected:
    std::string name;

public:
    Person(std::string name);

    std::string getName() const;
};