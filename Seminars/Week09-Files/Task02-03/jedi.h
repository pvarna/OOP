#pragma once

#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include <string>

const std::size_t INITIAL_CAPACITY = 2;
const std::size_t INCREASE_STEP = 2;

class Jedi
{
private:
    static int version;
    char** skills;
    std::size_t size;
    std::size_t capacity;
    int age;

    void copy(const Jedi& other);
    void deallocate();
    void resize();

public:
    Jedi();
    Jedi(const Jedi& other);
    Jedi& operator = (const Jedi& other);
    ~Jedi();

    void setAge(int age);
    void addNewSkill(const char* skill);
    
    void read(const char* filename);
    void write(const char* filename);

    friend std::ostream& operator << (std::ostream& out, const Jedi& jedi);
};

