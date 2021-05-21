#pragma once

#include "car.h"

class SportCar : public Car
{
public:
    SportCar(double maxSpeed, double currentSpeed, double price);
    void accelerate();
};