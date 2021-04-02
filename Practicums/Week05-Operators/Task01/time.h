#pragma once

class Time
{
private:
    int hours;
    int minutes;

public:
    Time();
    Time(const int hours, const int minutes);

    Time& operator = (const Time& other);
    Time& operator += (const Time& other);
    Time operator + (const Time& other);
    Time operator + (const int hours);
    friend Time operator + (const int hours, Time& other);
    bool operator > (const Time& other);

    void print();
};