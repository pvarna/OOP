#include <iostream>

#include "familyCar.h"
#include "sportCar.h"

int main ()
{
    SportCar sc(240, 0, 20000);
    FamilyCar fc(120, 0, 5000);

    std::cout << sc.getCurrentSpeed() << std::endl;
    std::cout << fc.getCurrentSpeed() << std::endl;
    std::cout << std::boolalpha << sc.isEngineOn() << std::endl;
    std::cout << std::boolalpha << fc.isEngineOn() << std::endl;

    std::cout << sc.getMaxSpeed() << std::endl;
    std::cout << fc.getMaxSpeed() << std::endl;

    sc.startMovement();
    fc.startMovement();

    std::cout << sc.getCurrentSpeed() << std::endl;
    std::cout << fc.getCurrentSpeed() << std::endl;
    std::cout << std::boolalpha << sc.isEngineOn() << std::endl;
    std::cout << std::boolalpha << fc.isEngineOn() << std::endl;

    sc.stopMovement();
    fc.stopMovement();

    std::cout << sc.getCurrentSpeed() << std::endl;
    std::cout << fc.getCurrentSpeed() << std::endl;
    std::cout << std::boolalpha << sc.isEngineOn() << std::endl;
    std::cout << std::boolalpha << fc.isEngineOn() << std::endl;

    sc.startMovement();
    fc.startMovement();

    sc.accelerate();
    fc.accelerate();

    std::cout << sc.getCurrentSpeed() << std::endl;
    std::cout << fc.getCurrentSpeed() << std::endl;
    std::cout << std::boolalpha << sc.isEngineOn() << std::endl;
    std::cout << std::boolalpha << fc.isEngineOn() << std::endl;

    return 0;
}