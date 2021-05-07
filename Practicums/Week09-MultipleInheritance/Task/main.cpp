#include "facultyMember.h"
#include <iostream>
#include <fstream>

int main ()
{
    FacultyMember pesho("Pesho", 82214, 2000);

    std::cout << pesho.getName() << std::endl;
    std::cout << pesho.getNumber() << std::endl;
    std::cout << pesho.getSalary() << std::endl;

    FacultyMember gosho;

    std::cin >> gosho;
    std::cout << gosho << std::endl;

    // write
    std::string fileName;
    std::cout << "Enter file name: ";
    getline(std::cin, fileName);
    std::ofstream fileTo(fileName);
    gosho.write(fileTo);
    fileTo.close();

    // read
    std::ifstream fileFrom(fileName);
    FacultyMember goshoCopy;
    goshoCopy.read(fileFrom);
    fileFrom.close();

    std::cout << goshoCopy << std::endl;
    
    return 0;
}