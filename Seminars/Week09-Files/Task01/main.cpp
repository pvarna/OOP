#include <iostream>
#include <fstream>
#include <string>
#include <cstddef>

int main ()
{
    std::size_t counter = 0;
    std::ifstream file;
    file.open("test.txt");

    if (!file.is_open())
    {
        std::cout << "Problem while opening the file!" << std::endl;
        return 1;
    }

    std::string buffer;
    while (!file.eof())
    {
        getline(file, buffer);
        std::cout << buffer << std::endl;
        ++counter;
    }

    file.seekg(0, std::ios::end); //set the position at the end of the file
    int size = file.tellg(); //get the current position
    file.seekg(0, std::ios::beg); //set the position at the beginning

    std::cout << "Number of lines in the file: " << counter << std::endl;
    std::cout << "Size of the file: " << size << " bytes" << std::endl;

    file.close();

    return 0;
}