#include <iostream>
#include <fstream>
#include <string>

int main ()
{
    std::ifstream file("selfPrintingFile.cpp");

    if (file.fail())
    {
        std::cout << "Error!" << std::endl;
        return 1;
    }

    while (!file.eof())
    {
        std::string temp;
        getline(file, temp);
        std::cout << temp << std::endl;
    }

    file.close();

    return 0;
}