#include <iostream>
#include "universe.h"

Universe::Universe(bool* grid, int rows, int cols) 
{
    this->initAliveCells(grid, rows, cols);
}

Universe::Universe(const Universe& other) 
{
    this->copy(other);
}

Universe& Universe::operator = (const Universe& other) 
{
    if (this != &other) 
    {
        this->destroy();
        this->copy(other);
    }

    return *this;
}

Universe::~Universe() 
{
    this->destroy();
}

bool Universe::isCellAlive(int r, int c) const 
{
    Cell cell(r, c);
    for (int i = 0; i < this->aliveCellsCount; i++) 
    {
        if (this->aliveCells[i] == cell) 
        {
            return true;
        }
    }

    return false;
}

void Universe::setAlive(int r, int c) 
{
    if (!this->isCellAlive(r, c)) 
    {
        this->expandTheAliveCellsAndAdd(r, c);
    }
}

int Universe::getNumberOfAliveNeighbours(int x, int y) const 
{
    int neighbours = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            neighbours += this->isCellAlive(x + dx, y + dy);
        }
    }
    neighbours -= this->isCellAlive(x, y);

    return neighbours;
}

int Universe::getFirstRow() const 
{
    int firstRow = 0;
    for (int i = 0; i < this->aliveCellsCount; i++) {
        if (firstRow > this->aliveCells[i].getRow()) {
            firstRow = this->aliveCells[i].getRow();
        }
    }

    return firstRow - 1;
}

int Universe::getLastRow() const 
{
    int lastRow = 0;
    for (int i = 0; i < this->aliveCellsCount; i++) 
    {
        if (lastRow < this->aliveCells[i].getRow()) 
        {
            lastRow = this->aliveCells[i].getRow();
        }
    }

    return lastRow + 2;
}

int Universe::getFirstCol() const 
{
    int firstCol = 0;
    for (int i = 0; i < this->aliveCellsCount; i++) 
    {
        if (firstCol > this->aliveCells[i].getCol()) 
        {
            firstCol = this->aliveCells[i].getCol();
        }
    }

    return firstCol - 1;
}

int Universe::getLastCol() const 
{
    int lastCol = 0;
    for (int i = 0; i < this->aliveCellsCount; i++) 
    {
        if (lastCol < this->aliveCells[i].getCol()) 
        {
            lastCol = this->aliveCells[i].getCol();
        }
    }

    return lastCol + 2;
}

bool Universe::operator == (const Universe& other) const 
{
    int minFirstRow = std::min(this->getFirstRow(), other.getFirstRow());
    int minFirstCol = std::min(this->getFirstCol(), other.getFirstCol());
    int maxLastRow = std::max(this->getLastRow(), other.getLastRow());
    int maxLastCol = std::max(this->getLastCol(), other.getLastCol());

    for (int i = minFirstRow; i < maxLastRow; i++) 
    {
        for (int j = minFirstCol; j < maxLastCol; j++) 
        {
            if (this->isCellAlive(i, j) != other.isCellAlive(i, j)) 
            {
                return false;
            }
        }
    }

    return true;
}

bool Universe::operator != (const Universe& other) const 
{
    return !this->operator==(other);
}

void Universe::print() const 
{
    for (int i = getFirstRow(); i < getLastRow(); i++) 
    {
        std::cout << "|";
        for (int j = getFirstCol(); j < getLastCol(); j++) 
        {
            std::cout << " " << this->isCellAlive(i, j) << " | ";
        }
        std::cout << std::endl;
    }
}

void Universe::expandTheAliveCellsAndAdd(int row, int col) 
{
    Cell newCell(row, col);
    Cell * newAliveCells = new Cell[this->aliveCellsCount + 1];

    for (int i = 0; i < this->aliveCellsCount; i++) 
    {
        newAliveCells[i] = this->aliveCells[i];
    }

    newAliveCells[this->aliveCellsCount] = newCell;

    delete[] this->aliveCells;
    this->aliveCells = newAliveCells;
    this->aliveCellsCount++;
}


void Universe::copy(const Universe& other) 
{
    copy(other.aliveCells, other.aliveCellsCount);
}

void Universe::copy(Cell* aliveCells, int aliveCellsCount) 
{
    this->aliveCellsCount = aliveCellsCount;
    this->aliveCells = new Cell[aliveCellsCount];

    for (int i = 0; i < aliveCellsCount; i++) 
    {
        this->aliveCells[i] = aliveCells[i];
    }
}

void Universe::initAliveCells(bool * grid, int rows, int cols) 
{
    this->aliveCellsCount = 0;
    for (int i = 0; i < rows * cols; i++) 
    {
        if (grid[i]) 
        {
            this->aliveCellsCount++;
        }
    }

    this->aliveCells = new Cell[this->aliveCellsCount];

    int k = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (grid[i * cols + j]) 
            {
                Cell cell(i, j);
                this->aliveCells[k++] = cell;
            }
        }
    }
}

void Universe::destroy() 
{
    if (this->aliveCells) 
    {
        delete[] this->aliveCells;
    }
}
