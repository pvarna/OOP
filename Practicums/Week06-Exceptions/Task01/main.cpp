#include <iostream>
#include "queue.h"

int main ()
{
    Queue myQueue(10);

    std::cout << std::boolalpha << myQueue.empty() << std::endl;

    int index1 = myQueue.getTicket("Pesho", "0887878787", 3945);
    int index2 = myQueue.getTicket("Teo", "0888888888", 1212);

    std::cout << std::boolalpha << myQueue.empty() << std::endl;

    std::cout << index1 << std::endl;
    std::cout << index2 << std::endl;

    std::cout << myQueue.getSize() << std::endl;

    std::cout << myQueue[0] << std::endl;
    std::cout << myQueue[1] << std::endl;

    Ticket firstTicket = myQueue.next();

    std::cout << firstTicket << std::endl;

    std::cout << myQueue.getSize() << std::endl;

    firstTicket = myQueue.next();

    std::cout << firstTicket << std::endl;

    std::cout << myQueue.getSize() << std::endl;

    std::cout << std::boolalpha << myQueue.empty() << std::endl;

    return 0;
}