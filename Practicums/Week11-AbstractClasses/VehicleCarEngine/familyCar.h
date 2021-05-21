#pragma once

#include "car.h"

class FamilyCar : public Car
{
public:
    FamilyCar(double maxSpeed, double currentSpeed, double price);
    void accelerate();
};