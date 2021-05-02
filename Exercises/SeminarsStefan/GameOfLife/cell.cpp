#include "cell.h"

Cell::Cell(int row, int col) 
{
    this->row = row;
    this->col = col;
}

int Cell::getRow() const 
{
    return this->row;
}

int Cell::getCol() const 
{
    return this->col;
}

bool Cell::operator == (const Cell & other) 
{
    return this->row == other.row && this->col == other.col;
}