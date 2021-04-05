#include <iostream>
#include "time.h"

Time::Time()
{
    this->hours = 0;
    this->minutes = 0;
}

Time::Time(const int hours, const int minutes)
{
    if (hours >=0 && hours <= 23)
    {
        this->hours = hours;
    }
    else
    {
        std::cout << "The hours must be between 0 and 23" << std::endl;
        this->hours = 0;
    }
    
    if (minutes >=0 && minutes <= 59)
    {
        this->minutes = minutes;
    }
    else
    {
        std::cout << "The minutes must be between 0 and 59" << std::endl;
        this->minutes = 0;
    }
}

Time& Time::operator = (const Time& other)
{
    if (this != &other)
    {
        this->hours = other.hours;
        this->minutes = other.minutes;   
    }

    return *this;
}

Time& Time::operator += (const Time& other)
{
    int thisMinutes = 60 * this->hours + this->minutes;
    int otherMinutes = 60 * other.hours + other.minutes;
    
    thisMinutes += otherMinutes;
    if (thisMinutes > 24 * 60)
    {
        thisMinutes -= 24 * 60;
    }

    this->hours = thisMinutes / 60;
    this->minutes = thisMinutes % 60;

    return *this;
}

Time Time::operator + (const Time& other)
{
    *this += other;

    return *this;
}

Time Time::operator + (const int hours)
{
    Time other(hours, 0);

    return *this + other;
}

Time operator + (const int hours, Time& other)
{
    return other + hours;
}

bool Time::operator > (const Time& other)
{
    int thisMinutes = this->hours*60 + this->minutes;
    int otherMinutes = other.hours*60 + other.minutes;

    return thisMinutes > otherMinutes;
}

bool operator > (const Time& left, const Time& right)
{
    int leftMinutes = left.hours*60 + left.minutes;
    int rightMinutes = right.hours*60 + right.minutes;

    return leftMinutes > rightMinutes;
}

void Time::print()
{
    std::cout << ((this->hours < 10) ? "0" : "") << this->hours << ":"
              << ((this->minutes < 10) ? "0" : "") << this->minutes << std::endl;

}

bool Time::operator == (const Time& other)
{
    return (this->hours == other.hours && this->minutes == other.minutes);
}

bool operator == (const Time& left, const Time& right)
{
    return (left.hours == right.hours && left.minutes == right.minutes);
}

void Time::setHours (const int hours)
{
    this->hours = hours;
}

void Time::setMinutes (const int minutes)
{
    this->minutes = minutes;
}