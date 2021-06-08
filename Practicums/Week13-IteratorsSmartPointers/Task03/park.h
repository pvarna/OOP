#pragma once

#include <string>

class Park
{
private:
    std::string name;

public:
    Park(std::string name);

    std::string getName() const;
};