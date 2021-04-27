#include <iostream>
#include "jedi.h"

int main ()
{
    Jedi pesho, gosho;

    pesho.addNewSkill("survives in FMI");
    pesho.addNewSkill("sleeps");
    pesho.addNewSkill("eats");

    pesho.write("jedi1.txt");
    
    gosho.read("jedi2.txt");

    std::cout << gosho;

    return 0;
}