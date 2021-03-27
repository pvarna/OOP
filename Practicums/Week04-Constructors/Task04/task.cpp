#include <iostream>
#include <cstring>
#include "task.h"

Task::Task()
{
    this->title = nullptr;
    this->description = nullptr;
}

Task::Task(const char* title, const char* description)
{
    this->title = new char[strlen(title) + 1];
    strcpy(this->title, title);

    this->description = new char[strlen(description) + 1];
    strcpy(this->description, description);
}

Task::Task(const Task& other)
{
    this->title = new char[strlen(other.title) + 1];
    strcpy(this->title, other.title);

    this->description = new char[strlen(other.description) + 1];
    strcpy(this->description, other.description);
}

Task& Task::operator = (const Task& other)
{
    if (this != &other)
    {
        if (this->title)
        {
            delete[] this->title;
        }
        this->title = new char[strlen(other.title) + 1];
        strcpy(this->title, other.title);

        if (this->description)
        {
            delete[] this->description;
        }
        this->description = new char[strlen(other.description) + 1];
        strcpy(this->description, other.description);
    }

    return *this;
}

std::ostream& operator << (std::ostream& out, const Task& task)
{
    out << task.title << " - " << task.description;

    return out;
}

std::istream& operator >> (std::istream& in, Task& task)
{
    char buffer[200];
    std::cout << "Please enter the title of the task: ";
    in.getline(buffer, 200);
    if (task.title)
    {
        delete[] task.title;
    }
    task.title = new char[strlen(buffer) + 1];
    strcpy(task.title, buffer);

    std::cout << "Please enter a brief description of the task: ";
    in.getline(buffer, 200);
    if (task.description)
    {
        delete[] task.description;
    }
    task.description = new char[strlen(buffer) + 1];
    strcpy(task.description, buffer);

    return in;
}

Task::~Task()
{
    delete[] title;
    delete[] description;
}