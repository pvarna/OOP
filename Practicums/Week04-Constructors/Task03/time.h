#pragma once

enum TimeZone
{
    NewYork,
    London,
    Sofia,
    Moscow
};

class Time
{
private:
    TimeZone city;
    int hours;
    int minutes;

    void addHours(int hours);

public:
    Time();
    Time(const TimeZone city, const int hours, const int minutes);

    Time getTimeInNewYork();
    Time getTimeInLondon();
    Time getTimeInSofia();
    Time getTimeInMoscow();

    int getHours() const;
    int getMinutes() const;
};