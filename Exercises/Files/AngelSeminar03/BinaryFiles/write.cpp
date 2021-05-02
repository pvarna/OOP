#include <iostream>
#include <fstream>

int main ()
{
    std::ofstream file("file.dat", std::ios::binary);

    int a = 155555;

    file.write((const char*)&a, sizeof(int));

    return 0;
}