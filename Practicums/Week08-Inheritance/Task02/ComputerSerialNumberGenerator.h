#pragma once

class ComputerSerialNumberGenerator
{
private:
    static int generatedNumber;

public:
    static int generateSerialNumber();
};