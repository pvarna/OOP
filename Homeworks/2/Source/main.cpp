#include "../Headers/informationSystem.h"

int main (int argc, char* argv[])
{
    InformationSystem is;

    if (argc == 2)
    {
        is.loadDataFromFile(argv[1]);
    }

    is.start();

    return 0;
}

