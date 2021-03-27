#include <iostream>
#include "time.h"

int main ()
{
    Time time1(NewYork, 12, 30);

    std::cout << "New York: " << time1.getTimeInNewYork().getHours() << ":" << time1.getTimeInNewYork().getMinutes() << std::endl;
    std::cout << "London: " << time1.getTimeInLondon().getHours() << ":" << time1.getTimeInLondon().getMinutes() << std::endl;
    std::cout << "Sofia: " << time1.getTimeInSofia().getHours() << ":" << time1.getTimeInSofia().getMinutes() << std::endl;
    std::cout << "Moscow: " << time1.getTimeInMoscow().getHours() << ":" << time1.getTimeInMoscow().getMinutes() << std::endl;

    return 0;
}