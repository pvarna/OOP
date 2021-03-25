#pragma once

class Polynom
{
private:
    int maxN;
    double* coefficients;

    void copy(const Polynom& other);
    void deallocate();
    void extend(const int newMaxN);

public:
    Polynom(int maxN = 10);
    Polynom(const Polynom& other);
    Polynom& operator = (const Polynom& other);
    ~Polynom();

    double getCoefficient(const int n) const;
    void setCoefficient(const int n, const double coefValue);

    void print() const;

    Polynom& operator += (const Polynom& other);
    Polynom& operator -= (const Polynom& other);

    Polynom operator + (const Polynom& other);
    Polynom operator - (const Polynom& other);

    bool operator == (const Polynom& other);
    bool operator != (const Polynom& other);

    Polynom getDerivative();
};