#include "set.h"
#include <iostream>

int main ()
{
    Set<int> set1, set2;

    set1.add(1);
    set1.add(2);
    set1.add(3);
    set1.add(4);
    set1.add(5);

    set2.add(1);
    set2.add(3);
    set2.add(4);
    set2.add(7);
    set2.add(9);

    std::cout << set1 << std::endl;
    std::cout << set2 << std::endl;

    Set<int> set3 = set1 + set2;
    Set<int> set4 = set1 * set2;
    Set<int> set5 = set1 - set2;
    std::cout << set3 << std::endl;
    std::cout << set4 << std::endl;
    std::cout << set5 << std::endl;
    
    return 0;
}