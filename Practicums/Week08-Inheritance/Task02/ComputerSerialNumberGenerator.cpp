#include "ComputerSerialNumberGenerator.h"

int ComputerSerialNumberGenerator::generatedNumber = 1000;

int ComputerSerialNumberGenerator::generateSerialNumber()
{
    return generatedNumber++;
}