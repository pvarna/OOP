#include "engine.h"

Engine::Engine()
{
    this->state = false;
}

void Engine::start()
{
    this->state = true;
}

void Engine::stop()
{
    this->state = false;
}

bool Engine::getState() const
{
    return this->state;
}