#include <iostream>
#include "Computer.h"

Computer::Computer(std::string hardDrive, std::string videoCard, std::string processor, std::string ram)
                : hardDrive(hardDrive), videoCard(videoCard), processor(processor), ram(ram)
{
    this->serialNumber = ComputerSerialNumberGenerator::generateSerialNumber();
}

void Computer::print()
{
    std::cout << "Serial number: " << this->serialNumber << std::endl;
    this->hardDrive.print();
    this->videoCard.print();
    this->processor.print();
    this->ram.print();
}