#include <iostream>
#include <cmath>
#include "toDoList.h"

ToDoList::ToDoList()
{
    this->capacity = 2;
    this->tasks = new Task[this->capacity];
}

ToDoList::ToDoList(const size_t capacity)
{
    this->tasks = new Task[capacity];
    this->capacity = capacity;
}

ToDoList::~ToDoList()
{
    delete[] this->tasks;
}

void ToDoList::resize()
{
    this->capacity *= 2;

    Task* newTasks = new Task[this->capacity];
    for (int i = 0; i < this->size; ++i)
    {
        newTasks[i] = this->tasks[i];
    }

    delete[] this->tasks;
    this->tasks = newTasks;

    std::cout << "Capacity expanded from " << this->capacity/2 << " to " << this->capacity << "!" << std::endl;
}

void ToDoList::pushTask(const Task task)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }

    this->tasks[this->size] = task;
    ++this->size;
}

Task ToDoList::popTask()
{
    Task result = this->tasks[0];
    
    for (int i = 0; i < this->size-1; ++i)
    {
        tasks[i] = tasks[i+1];
    }

    if (!this->isEmpty())
    {
        --this->size;
    }

    return result;
}

void ToDoList::printSize()
{
    std::cout << "Number of tasks: " << this->size << std::endl;
    std::cout << "Capacity of the list: " << this->capacity << std::endl;
    std::cout << "The list is " << ((double)this->size)/((double)this->capacity)*100 << "% full" << std::endl;
}

bool ToDoList::isEmpty()
{
    return this->size == 0;
}