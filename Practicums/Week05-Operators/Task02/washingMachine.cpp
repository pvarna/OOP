#include <iostream>
#include <cstring>
#include "washingMachine.h"

WashingMachine::WashingMachine()
{
    for (int i = 0; i < MAX_STR_LENGTH; ++i)
    {
        this->manufacturer[i] = '\0';
        this->model[i] = '\0';
    }
    this->massLaundry = 0;
    this->electricalConsumption = 0;
    this->waterConsumption = 0;
}

WashingMachine::WashingMachine(const char* manufacturer, const char* model, const int massLaundry, 
                   const double electricalConsumption, const int waterConsumption)
{
    strcpy(this->manufacturer, manufacturer);
    strcpy(this->model, model);
    this->massLaundry = massLaundry;
    this->electricalConsumption = electricalConsumption;
    this->waterConsumption = waterConsumption;
}

bool WashingMachine::operator > (const WashingMachine& other) const
{
    return (this->massLaundry > other.massLaundry) || 
           (this->massLaundry == other.massLaundry && this->electricalConsumption < other.electricalConsumption) || 
           
           (this->massLaundry == other.massLaundry && this->electricalConsumption == other.electricalConsumption && 
           this->waterConsumption < other.waterConsumption); 
}

void WashingMachine::setMassLaundry(const int massLaundry)
{
    this->massLaundry = massLaundry;
}

void WashingMachine::setElConsumption(const double electricalConsumption)
{
    this->electricalConsumption = electricalConsumption;
}

void WashingMachine::setWaterConsuption(const double waterConsumption)
{
    this->waterConsumption = waterConsumption;
}

std::ostream& operator << (std::ostream& out, const WashingMachine& washingMachine)
{
    out << "Manufacturer: " << washingMachine.manufacturer << std::endl;
    out << "Model: " << washingMachine.model;

    return out;
}

std::istream& operator >> (std::istream& in,  WashingMachine& washingMachine)
{
    std::cout << "Please enter the name of the manufacturer: ";
    in.getline(washingMachine.manufacturer, MAX_STR_LENGTH);

    std::cout << "Please enter the model of the washing machine: ";
    in.getline(washingMachine.model, MAX_STR_LENGTH);

    std::cout << "Please enter the max mass of the laundry: ";
    in >> washingMachine.massLaundry;

    std::cout << "Please enter the electical consumption: ";
    in >> washingMachine.electricalConsumption;

    std::cout << "Please enter the water consumption: ";
    in >> washingMachine.waterConsumption;
    in.ignore();

    return in;
}