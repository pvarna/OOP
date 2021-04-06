#pragma once

class Time
{
private:
    int hours;
    int minutes;

public:
    Time();
    Time(const int hours, const int minutes);

    void setHours (const int hours);
    void setMinutes (const int minutes);

    Time& operator = (const Time& other);
    Time& operator += (const Time& other);
    Time operator + (const Time& other);
    Time operator + (const int hours);
    friend Time operator + (const int hours, Time& other);
    bool operator > (const Time& other) const;
    bool operator == (const Time& other);
    friend bool operator == (const Time& left, const Time& right);

    void print();
};