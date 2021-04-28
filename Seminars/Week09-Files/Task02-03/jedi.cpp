#include "jedi.h"

int Jedi::version = 1;

Jedi::Jedi()
{
    this->skills = new char*[INITIAL_CAPACITY];
    this->capacity = INITIAL_CAPACITY;
    this->size = 0;
    this->age = 0;
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
    this->age = other.age;
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

void Jedi::setAge(int age)
{
    this->age = age;
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

    this->deallocate();

    file >> this->version >> this->size >> this->capacity;
    if (this->version >= 1)
    {
        file >> this->age;
    }
    else
    {
        this->age = 0;
    }

    this->skills = new char*[this->capacity];

    for (std::size_t i = 0; i < this->size; ++i)
    {
        std::size_t skillLength = 0;
        file >> skillLength;

        this->skills[i] = new char[skillLength + 1];

        file.get();
        file.getline(this->skills[i], skillLength + 1);
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

    file << this->version << " " << this->size << " " << this->capacity << " " << this->age << std::endl; 
    for (std::size_t i = 0; i < this->size; ++i)
    {
        file << strlen(this->skills[i]) << " " << this->skills[i] << std::endl;
    }

    file.close();
}

std::ostream& operator << (std::ostream& out, const Jedi& jedi)
{
    out << jedi.version << " " << jedi.size << " " << jedi.capacity << " " << jedi.age << std::endl;
    for (std::size_t i = 0; i < jedi.size; ++i)
    {
        out << jedi.skills[i] << std::endl;
    }
    
    return out;
}