#include "gameOfLife.h"

GameOfLife::GameOfLife(Universe seed) : 
    universe(seed) 
{}

void GameOfLife::tick() 
{
    /*
        ----> Any live cell with fewer than two live neighbours dies, as if by underpopulation.
        ----> Any live cell with two or three live neighbours lives on to the next generation.
        ----> Any live cell with more than three live neighbours dies, as if by overpopulation.
        Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    */
    // TODO: apply all rules

    Universe nextGeneration(nullptr, 0, 0);

    for (int i = this->universe.getFirstRow(); i < this->universe.getLastRow(); i++) 
    {
        for (int j = this->universe.getFirstCol(); j < this->universe.getLastCol(); j++) 
        {
            int aliveNeighbours = this->universe.getNumberOfAliveNeighbours(i, j);

            if (this->universe.isCellAlive(i, j)) 
            {
                if (2 == aliveNeighbours || 3 == aliveNeighbours) 
                {
                    nextGeneration.setAlive(i, j);
                }
            } 
            else 
            {
                if (3 == aliveNeighbours) 
                {
                    nextGeneration.setAlive(i, j);
                }
            }
        }
    }

    this->universe = nextGeneration;
}

Universe GameOfLife::getUniverse() const 
{
    return this->universe;
}


void GameOfLife::print() const 
{
    this->universe.print();
}
