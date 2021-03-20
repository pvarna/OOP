#pragma once

class Triangle
{
    private:
        double sideA;
        double sideB;
        double sideC;

        bool validate();

    public:
        void input();
        double perimeter();
        double area();
};
