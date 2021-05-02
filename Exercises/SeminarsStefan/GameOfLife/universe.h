#pragma once

#include "cell.h"

class Universe {
private:
	Cell* aliveCells;
	int aliveCellsCount;

    void expandTheAliveCellsAndAdd(int row, int col);
	void copy(const Universe & other);
	void copy(Cell* aliveCells, int aliveCellsCount);
	void initAliveCells(bool* grid, int rows, int cols);
	void destroy();

public:
	Universe(bool* grid, int rows, int cols);
	Universe(const Universe & other);
	Universe& operator=(const Universe & other);
	~Universe();

	bool isCellAlive(int r, int c) const;
	void setAlive(int r, int c);

	int getNumberOfAliveNeighbours(int x, int y) const;

	int getFirstRow() const;
	int getLastRow() const;
	int getFirstCol() const;
	int getLastCol() const;

	bool operator == (const Universe & other) const;
	bool operator != (const Universe & other) const;

	void print() const;
};
