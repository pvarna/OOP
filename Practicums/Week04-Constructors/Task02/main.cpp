#include <iostream>
#include "horo.h"

int main ()
{
    Horo pravo("pravo", "2/4", Trakiiski), daichovo("daichovo", "7/8", Severnyashki);

    pravo.print();
    daichovo.print();

    return 0;
}