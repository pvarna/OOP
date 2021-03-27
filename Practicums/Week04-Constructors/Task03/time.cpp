#include "time.h"

Time::Time()
{
    this->city = NewYork;
    this->hours = 0;
    this->minutes = 0;
}

Time::Time(const TimeZone city, const int hours, const int minutes)
{
    this->city = city;
    this->hours = hours;
    this->minutes = minutes;
}

void Time::addHours(int hours)
{
    this->hours += hours;
    if (this->hours > 23)
    {
        this->hours -= 24;
    }
    if (this->hours < 0)
    {
        this->hours += 24;
    }
}

Time Time::getTimeInNewYork()
{
    Time result;
    
    result.city = NewYork;
    result.hours = this->hours;
    switch (this->city)
    {
    case 0:
        result.addHours(0);
        break;
    case 1:
        result.addHours(-5);
        break;
    case 2:
        result.addHours(-7);
        break;
    case 3:
        result.addHours(-8);
        break;
    }

    result.minutes = this->minutes;

    return result;
}

Time Time::getTimeInLondon()
{
    Time result;
    
    result.city = London;
    result.hours = this->hours;
    switch (this->city)
    {
    case 0:
        result.addHours(5);
        break;
    case 1:
        result.addHours(0);
        break;
    case 2:
        result.addHours(-2);
        break;
    case 3:
        result.addHours(-3);
        break;
    }

    result.minutes = this->minutes;

    return result;   
}

Time Time::getTimeInSofia()
{
    Time result;
    
    result.city = Sofia;
    result.hours = this->hours;
    switch (this->city)
    {
    case 0:
        result.addHours(7);
        break;
    case 1:
        result.addHours(2);
        break;
    case 2:
        result.addHours(0);
        break;
    case 3:
        result.addHours(-1);
        break;
    }

    result.minutes = this->minutes;

    return result;   
}

Time Time::getTimeInMoscow()
{
    Time result;
    
    result.city = Moscow;
    result.hours = this->hours;
    switch (this->city)
    {
    case 0:
        result.addHours(8);
        break;
    case 1:
        result.addHours(3);
        break;
    case 2:
        result.addHours(1);
        break;
    case 3:
        result.addHours(0);
        break;
    }

    result.minutes = this->minutes;

    return result;   
}

int Time::getHours() const
{
    return this->hours;
}

int Time::getMinutes() const
{
    return this->minutes;
}