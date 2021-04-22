#pragma once

class ComponentSerialNumberGenerator
{
private:
    static int generatedNumber;

public:
    static int generateSerialNumber();
};