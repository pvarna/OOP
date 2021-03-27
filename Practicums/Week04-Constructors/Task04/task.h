#pragma once

class Task
{
    private:
        char* title;
        char* description;

    public:
        Task();
        Task(const char* title, const char* description);
        Task(const Task& other);

        Task& operator = (const Task& other);
        friend std::ostream& operator << (std::ostream& out, const Task& task);
        friend std::istream& operator >> (std::istream& in, Task& task);
        
        ~Task();
};