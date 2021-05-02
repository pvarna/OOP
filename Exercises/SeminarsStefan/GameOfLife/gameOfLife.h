#pragma once

#include "universe.h"

class GameOfLife 
{
private:
	Universe universe;

public:
	GameOfLife(Universe seed);

	void tick();

	Universe getUniverse() const;

	void print() const;
};