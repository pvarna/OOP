#include <iostream>
#include "human.h"

Human::Human(std::string name, std::string family, unsigned int age)
{
    this->name = name;
    this->family = family;
    this->age = age;
}

void Human::print()
{
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Family: " << this->family << std::endl;
    std::cout << "Age: " << this->age << std::endl;
}