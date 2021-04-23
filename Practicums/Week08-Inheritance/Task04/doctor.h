#pragma once

#include <string>

class Doctor
{
protected:
    std::string name;

public:
    Doctor(std::string name);

    void performSurgery();
};