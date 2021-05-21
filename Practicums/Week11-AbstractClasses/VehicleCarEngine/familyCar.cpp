#include "familyCar.h"

#include <iostream>

const double INCREASE_SPEED_FAMILY_CAR = 10;

FamilyCar::FamilyCar(double maxSpeed, double currentSpeed, double price) 
    : Car(maxSpeed, currentSpeed, price)
{}

void FamilyCar::accelerate()
{
    if (!this->engine.getState())
    {
        throw std::logic_error("The car isn't moving");
    }

    if (this->currentSpeed + INCREASE_SPEED_FAMILY_CAR > this->maxSpeed)
    {
        throw std::overflow_error("Max speed reached");
    }

    this->currentSpeed += INCREASE_SPEED_FAMILY_CAR;
}