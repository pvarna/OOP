#pragma once

class Pace
{
private:
    int minutesPace;
    int secondsPace;
    double speed;

public:
    Pace();
    Pace(const int minutesPace, const int secondsPace);
    Pace(const double speed);
    
    void setPace(const double pace);
    void setSpeed(const double speed);

    int* getPace() const;
    double getSpeed() const;

    //void print();
};