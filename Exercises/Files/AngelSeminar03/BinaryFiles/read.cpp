#include <iostream>
#include <fstream>

int main ()
{
    std::ifstream file("file.dat", std::ios::binary);

    int a;

    file.read((char*)&a, sizeof(int));

    std::cout << a << std::endl;

    return 0;
}