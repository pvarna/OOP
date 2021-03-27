#include <iostream>
#include <cmath>
#include "pace.h"


Pace::Pace()
{
    this->minutesPace = 0;
    this->secondsPace = 0;
    this->speed = 0;
}

Pace::Pace(const int minutesPace, const int secondsPace)
{
    this->minutesPace = minutesPace;
    this->secondsPace = secondsPace;

    int seconds = 60*minutesPace + secondsPace;
    this->speed = 3600/seconds;
}

Pace::Pace(const double speed)
{
    this->speed = speed;
    
    int seconds = 3600/speed;

    this->minutesPace = seconds / 60;
    this->secondsPace = seconds % 60;

}

int* Pace::getPace() const
{
    int* paceMinutesSeconds = new int[2];
    paceMinutesSeconds[0] = this->minutesPace;
    paceMinutesSeconds[1] = this->secondsPace;

    return paceMinutesSeconds;
}

double Pace::getSpeed() const
{
    return this->speed;
}