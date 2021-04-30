#include <iostream>
#include "game.h"

int main ()
{
    srand (time(NULL));
    Game UNO(2, 10);
    UNO.play();

    return 0;
}