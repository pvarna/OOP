#pragma once

#include <string>

class Shape
{
protected:
    std::string type;

public:
    Shape(std::string type);

    void print();
};