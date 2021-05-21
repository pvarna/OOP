#include "sportCar.h"

#include <iostream>

const double INCREASE_SPEED_SPORT_CAR = 50;

SportCar::SportCar(double maxSpeed, double currentSpeed, double price) 
    : Car(maxSpeed, currentSpeed, price)
{}

void SportCar::accelerate()
{
    if (!this->engine.getState())
    {
        throw std::logic_error("The car isn't moving");
    }

    if (this->currentSpeed + INCREASE_SPEED_SPORT_CAR > this->maxSpeed)
    {
        throw std::overflow_error("Max speed reached");
    }

    this->currentSpeed += INCREASE_SPEED_SPORT_CAR;
}