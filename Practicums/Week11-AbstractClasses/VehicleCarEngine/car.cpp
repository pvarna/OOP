#include "car.h"
#include <iostream>

const double STARTING_SPEED = 10;

void Car::startMovement()
{
    if (this->currentSpeed > 0)
    {
        throw std::logic_error("The car is already moving");
    }
    this->startEngine();
}

void Car::stopMovement()
{
    if (this->currentSpeed == 0)
    {
        throw std::logic_error("The car isn't moving");
    }
    this->stopEngine();
}

void Car::startEngine()
{
    this->currentSpeed = STARTING_SPEED;
    this->engine.start();
}

void Car::stopEngine()
{
    this->currentSpeed = 0;
    this->engine.stop();
}

Car::Car(double maxSpeed, double currentSpeed, double price)
{
    this->maxSpeed = maxSpeed;
    this->currentSpeed = currentSpeed;
    this->price = price;
    if (this->currentSpeed > 0)
    {
        this->engine.start();
    }
}

double Car::getMaxSpeed() const
{
    return this->maxSpeed;
}

double Car::getCurrentSpeed() const
{
    return this->currentSpeed;
}

bool Car::isEngineOn() const
{
    return this->engine.getState();
}