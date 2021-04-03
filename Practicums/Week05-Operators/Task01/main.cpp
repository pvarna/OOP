#include <iostream>
#include "time.h"

int main ()
{
    Time t1(10, 30), t2(5, 20);

    t1.print();
    t2.print();

    Time t3 = t1 + t2;
    t3.print();

    Time t4;
    t4 = t3 + 2;
    t4.print();

    Time t5;
    t5 = 3 + t4;
    t5.print();

    Time t10(10, 30), t11(10,30), t12(0, 0), t13;

    std::cout << std::boolalpha << (t10 == t11) << " " << (t12 == t13) << std::endl;

    return 0;
}