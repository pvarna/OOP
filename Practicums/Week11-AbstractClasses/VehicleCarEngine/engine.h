#pragma once

class Engine
{
private:
    bool state;

public:
    Engine();

    void start();
    void stop();

    bool getState() const;
};