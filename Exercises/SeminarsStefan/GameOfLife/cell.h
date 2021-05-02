#pragma once

class Cell 
{
private:
    int row;
    int col;

public:
	Cell(int row = 0, int col = 0);

	int getRow() const;
	int getCol() const;

	bool operator == (const Cell & other);
};