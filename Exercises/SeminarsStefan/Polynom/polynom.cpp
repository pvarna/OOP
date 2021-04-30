#include <iostream>
#include "polynom.h"

void Polynom::copy(const Polynom& other)
{
    this->maxN = other.maxN;
    this->coefficients = new double[this->maxN + 1];
    for (int i = 0; i < this->maxN+1; ++i)
    {
        this->coefficients[i] = other.coefficients[i]; 
    }
}

void Polynom::deallocate()
{
    if (this->coefficients)
    {
        delete[] this->coefficients;
    }
}

void Polynom::extend(const int newMaxN)
{
    if (this->maxN > newMaxN)
    {
        return;
    }

    double* newCoefficients = new double[newMaxN + 1];
    for (int i = 0; i < newMaxN+1; ++i)
    {
        newCoefficients[i] = this->getCoefficient(i);
    }

    delete[] this->coefficients;

    this->maxN = newMaxN;
    this->coefficients = newCoefficients;
}

Polynom::Polynom(int maxN)
{
    this->maxN = maxN;
    this->coefficients = new double[this->maxN + 1];
    for (int i = 0; i < this->maxN+1; ++i)
    {
        this->coefficients[i] = 0;
    }
}

Polynom::Polynom(const Polynom& other)
{
    copy(other);
}

Polynom::~Polynom()
{
    deallocate();
}

Polynom& Polynom::operator = (const Polynom& other)
{
    if (this != &other)
    {
        deallocate();
        copy(other);
    }

    return *this;
}

double Polynom::getCoefficient(const int n) const
{
    if (0 <= n && n <= this->maxN)
    {
        return this->coefficients[n];
    }
    return 0;
}

void Polynom::setCoefficient(const int n, const double coefValue)
{
    if (n > this->maxN)
    {
        this->extend(n);
    }

    if (0 <= n && n <= this->maxN)
    {
        this->coefficients[n] = coefValue;
    }
}

void Polynom::print() const
{
    bool isZero = true;
    int lastNotNullDegree = this->maxN;

    for (int i = 0; i < this->maxN+1; ++i)
    {
        if (this->coefficients[i] != 0)
        {
            lastNotNullDegree = i;
            break;
        }
    }
    for (int i = this->maxN; i >= 0; --i)
    {
        if (this->coefficients[i] != 0)
        {
            isZero = false;
            if (this->coefficients[i] != 1 && this->coefficients[i] != -1)
            {
                std::cout << coefficients[i];
            }
            else if (this->coefficients[i] == -1)
            {
                std::cout << "-";
            }
            switch (i)
            {
            case 0: 
                std::cout << "";
                break;
            case 1:
                std::cout << "x";
                break;
            default:
                std::cout << "x^" << i;
                break;
            }
            if (i != lastNotNullDegree)
            {
                std::cout << " + ";
            }
            else
            {
                std::cout << std::endl;
            }
        }
    }

    if (isZero)
    {
        std::cout << "0" << std::endl;
    }
}


Polynom& Polynom::operator += (const Polynom& other)
{
    for (int i = this->maxN; i >= 0; --i)
    {
        this->setCoefficient(i, this->getCoefficient(i) + other.getCoefficient(i));
    }

    return *this;
}

Polynom& Polynom::operator -= (const Polynom& other)
{
    for (int i = this->maxN; i >=0; --i)
    {
        this->setCoefficient(i, this->getCoefficient(i) - other.getCoefficient(i));
    }

    return *this;
}

Polynom Polynom::operator + (const Polynom& other)
{
    Polynom result = *this;
    result += other;

    return result;
}

Polynom Polynom::operator - (const Polynom& other)
{
    Polynom result = *this;
    result -= other;

    return result;
}

bool Polynom::operator == (const Polynom& other)
{
    if (this->maxN != other.maxN)
    {
        return false;
    }

    for (int i = 0; i < this->maxN+1; ++i)
    {
        if (this->getCoefficient(i) != other.getCoefficient(i))
        {
            return false;
        }
    }

    return true;
}

bool Polynom::operator != (const Polynom& other)
{
    return !(this->operator == (other));
}

Polynom Polynom::getDerivative ()
{
    Polynom result;
    result.maxN = this->maxN - 1;
    result.coefficients = new double[result.maxN + 1];

    for (int i = result.maxN; i >= 0; --i)
    {
        result.coefficients[i] = this->coefficients[i+1]*(i+1);
    }

    return result;
}