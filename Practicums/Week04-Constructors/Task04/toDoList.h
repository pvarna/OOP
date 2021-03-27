#pragma once

#include "task.h"

class ToDoList
{
    private:
        Task* tasks;
        size_t capacity;
        size_t size = 0;

        void resize();

    public:
        ToDoList();
        ToDoList(const size_t capacity);

        void pushTask(const Task task);
        Task popTask();
        void printSize();

        bool isEmpty();

        ~ToDoList();
};