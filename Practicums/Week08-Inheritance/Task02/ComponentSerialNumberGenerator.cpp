#include "ComponentSerialNumberGenerator.h"

int ComponentSerialNumberGenerator::generatedNumber = 100;

int ComponentSerialNumberGenerator::generateSerialNumber()
{
    return generatedNumber++;
}