#include <iostream>
#include "person.h"
#include "car.h"
#include "parking.h"

int main ()
{
    Person mime("Maria", 19, true), sonche("Sonya", 19, false), daian("Daian", 19, true), 
            teo("Teodor", 19, true), pesho("Peter", 19, true);

    Car car1(sonche, "BMW X5", "S SSSS S", BLACK), car2(daian, "BMW M5 F90 Competition", "X XXXX X", BLACK),
        car3(pesho, "BMW E36", "P PPPP P", BLACK), car4(teo, "BMW M4", "T TTTT T", BLACK),
        car5(mime, "BMW X6", "M MMMM M", BLACK), car6(sonche, "BMW X7", "S SSST S", BLACK);

    Parking parking;

    parking.addCar(car1);
    parking.addCar(car2);
    parking.addCar(car3);
    parking.addCar(car4);
    parking.addCar(car5);
    parking.addCar(car6);
    
    parking.printAllCars();
    std::cout << std::endl;

    parking.removeCar(3);
    parking.printAllCars();
    std::cout << std::endl;

    Person resultPerson = parking.getOwnerByLicensePlate("X XXXX X");
    resultPerson.print();

    std::cout << std::endl;

    size_t resultCount = 0;
    Car* resultCars = parking.getCarsByOwner("Sonya", resultCount);
    for (int i = 0; i < resultCount; ++i)
    {
        std::cout << "Car #" << i+1 << ":" << std::endl;
        resultCars[i].print();
    }

    return 0;
}