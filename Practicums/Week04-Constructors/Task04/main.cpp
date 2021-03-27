#include <iostream>
#include "toDoList.h"

int main ()
{
    ToDoList myList;

    std::cout << std::boolalpha << myList.isEmpty() << std::endl;

    for (int i = 0; i < 20; ++i)
    {
        Task temp("a", "a");

        myList.pushTask(temp);

        myList.printSize(); 

        //std::cout << std::boolalpha << myList.isEmpty() << std::endl;
    }

    for (int i = 19; i >= 0; --i)
    {
        std::cout << myList.popTask() << std::endl;

        myList.printSize();
    }

    /*Task myTask;

    std::cin >> myTask;

    myList.pushTask(myTask);

    myList.printSize();

    std::cout << std::boolalpha << myList.isEmpty() << std::endl;

    std::cin >> myTask;

    myList.pushTask(myTask);

    myList.printSize();

    std::cout << std::boolalpha << myList.isEmpty() << std::endl;

    std::cin >> myTask;

    myList.pushTask(myTask);

    myList.printSize();

    std::cout << std::boolalpha << myList.isEmpty() << std::endl;

    std::cout << myList.popTask() << std::endl;

    myList.printSize();*/

    return 0;
}