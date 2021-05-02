#include <iostream>
#include <cstddef>
#include <fstream>

std::size_t getFileSize(std::ifstream& file);

int main ()
{
    std::cout << "Enter file name:" << std::endl;
    std::cout << ">";

    char fileName[1024];
    std::cin.getline(fileName, 1024);

    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "Error" << std::endl;
        return -1;
    }

    std::cout << "Size: " << getFileSize(file) << std::endl;

    file.close();

    return 0;
}

std::size_t getFileSize(std::ifstream& file)
{
    file.seekg(0, std::ios::end);
    std::size_t size = file.tellg();
    file.seekg(0, std::ios::beg);

    return size;
}