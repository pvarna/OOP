#include "FnGenerator.h"

int FnGenerator::generatedId = 100000;

int FnGenerator::generateId()
{
    return generatedId++;
}