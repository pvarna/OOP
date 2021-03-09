#include "functions.h"
#include <iostream>

void Point::readPoint()
{
    std::cout << "x = ";
    std::cin >> x;
    std::cout << "y = ";
    std::cin >> y;
}

void Rectangular::readRectangular()
{
    std::cout << "Enter the coordinates of the upper left vertex of the rectangular:" << std::endl;
    upperLeft.readPoint();

    std::cout << "Enter the coordinates of the lower right vertex of the rectangular:" << std::endl;
    lowerRight.readPoint();
}

bool Rectangular::isPointContained(Point point)
{
    return ((point.x >= upperLeft.x && point.x <= lowerRight.x) && (point.y >= lowerRight.y && point.y <= upperLeft.y));
}

void Rectangular::printRectangle()
{
    if (upperLeft.x < 0 || upperLeft.y < 0)
    {
        std::cout << "The coordinates must be positive numbers" << std::endl;
        return;
    }

    int rows = (int)lowerRight.y;
    int columns = (int)lowerRight.x;

    char** matrix = new(std::nothrow) char*[rows];
    for (int i = 0; i < lowerRight.y; ++i)
    {
        matrix[i] = new(std::nothrow) char[columns];
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (i >= upperLeft.y && j >= upperLeft.x)
            {
                matrix[i][j] = '*';
            }
            else
            {
                matrix[i][j] = ' ';
            }
        }
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    
}

bool doRectanglesIntersect(Rectangular rectangular1, Rectangular rectangular2)
{
    if (std::max(rectangular1.upperLeft.x, rectangular2.upperLeft.x) > std::min(rectangular1.lowerRight.x, rectangular2.lowerRight.x))
    {
        return false;
    }

    if (std::max(rectangular1.lowerRight.y, rectangular2.lowerRight.y) > std::min(rectangular1.upperLeft.y, rectangular2.upperLeft.y))
    {
        return false;
    }

    return true;
}