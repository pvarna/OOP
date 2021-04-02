#pragma once

//#include <iostream>
#include "consts.h"

class WashingMachine
{
private:
    char manufacturer[MAX_STR_LENGTH];
    char model[MAX_STR_LENGTH];
    int massLaundry;
    double electricalConsumption;
    int waterConsumption;

public:
    WashingMachine();
    WashingMachine(const char* manufacturer, const char* model, const int massLaundry, 
                   const double electricalConsumption, const int waterConsumption);

    bool operator > (const WashingMachine& other);
    
    friend std::ostream& operator << (std::ostream& out, const WashingMachine& washingMachine);
    friend std::istream& operator >> (std::istream& in,  WashingMachine& washingMachine);
};

