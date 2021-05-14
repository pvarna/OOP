#pragma once

class Singleton
{
private:
    int a;
    double b;

    Singleton();

public:
    Singleton(const Singleton& other) = delete;
    Singleton& operator = (const Singleton& other) = delete;

    static Singleton& getInstance();

    int getA() const;
    double getB() const;

    void setA(int a);
    void setB(double b);
};