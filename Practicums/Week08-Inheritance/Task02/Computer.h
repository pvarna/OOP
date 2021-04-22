#pragma once

#include <string>
#include "ComputerSerialNumberGenerator.h"
#include "Component.h"
#include "HardDrive.h"
#include "VideoCard.h"
#include "Processor.h"
#include "RAM.h"

class Computer
{
private:
    int serialNumber;
    HardDrive hardDrive;
    VideoCard videoCard;
    Processor processor;
    RAM ram;

public:
    Computer(std::string hardDrive, std::string videoCard, std::string processor, std::string ram);
    
    void print();
};