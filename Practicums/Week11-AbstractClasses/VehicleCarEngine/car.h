#pragma once

#include "vehicle.h"
#include "engine.h"

class Car: public Vehicle
{
protected:
    double maxSpeed;
    double currentSpeed;
    double price;
    Engine engine;

    void startEngine();
    void stopEngine();

public:
    Car(double maxSpeed, double currentSpeed, double price);

    void startMovement();
    void stopMovement();
    virtual void accelerate() = 0;

    double getMaxSpeed() const;
    double getCurrentSpeed() const;
    bool isEngineOn() const;
};