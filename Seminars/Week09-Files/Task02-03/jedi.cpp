#include "jedi.h"

Jedi::Jedi()
{
    this->skills = new char*[INITIAL_CAPACITY];
    this->capacity = INITIAL_CAPACITY;
    this->size = 0;
}

void Jedi::copy(const Jedi& other)
{
    char** buffer = new char*[other.capacity];
    for (std::size_t i = 0; i < other.size; ++i)
    {
        buffer[i] = other.skills[i];
    }

    this->skills = buffer;
    this->size = other.size;
    this->capacity = other.capacity;
}

void Jedi::deallocate()
{
    for (std::size_t i = 0; i < this->size; ++i)
    {
        delete[] this->skills[i];
    }

    delete[] this->skills;
}

void Jedi::resize()
{
    char** buffer = new char*[this->capacity * INCREASE_STEP];
    for (std::size_t i = 0; i < this->size; ++i)
    {
        buffer[i] = this->skills[i];
    }

    this->skills = buffer;
    this->capacity *= INCREASE_STEP;
}

Jedi::Jedi(const Jedi& other)
{
    this->copy(other);
}

Jedi& Jedi::operator = (const Jedi& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

Jedi::~Jedi()
{
    this->deallocate();
}

void Jedi::addNewSkill(const char* skill)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }

    this->skills[this->size] = new char[strlen(skill) + 1];
    strcpy(this->skills[this->size++], skill);
}

void Jedi::read(const char* filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Error while opening the file" << std::endl;
    }

    int countOfLines = 0;
    while (!file.eof())
    {
        std::string temp;
        getline(file, temp);
        ++countOfLines;
    }

    while (this->capacity < countOfLines)
    {
        this->resize();
    }

    file.seekg(0, std::ios::beg);

    while (!file.eof())
    {
        char temp[1000];
        file.getline(temp, 1000);

        this->addNewSkill(temp);
    }

    file.close();
}

void Jedi::write(const char* filename)
{
    std::ofstream file(filename);

    if (!file.is_open())
    {
        std::cout << "Error while opening the file" << std::endl;
    }

    for (std::size_t i = 0; i < this->size; ++i)
    {
        file << this->skills[i] << std::endl;
    }

    file.close();
}

std::ostream& operator << (std::ostream& out, const Jedi& jedi)
{
    for (std::size_t i = 0; i < jedi.size; ++i)
    {
        out << jedi.skills[i] << std::endl;
    }

    return out;
}