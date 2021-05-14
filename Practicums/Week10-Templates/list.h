#pragma once

#include <iostream>
#include <string>
#include <fstream>

const std::size_t INITIAL_CAPACITY = 2;
const std::size_t INCREASE_STEP = 2;

template <class T>
class List
{
protected:
    T* data;
    std::size_t size;
    std::size_t capacity;

    void copy(const List<T>& other);
    void deallocate();
    void resize();
    bool contains(T element);

public:
    List();
    List(const List<T>& other);
    List<T>& operator = (const List<T>& other);
    ~List();

    void push_back(T element);
    void removeAt(std::size_t index);

    std::size_t getSize();
    bool isEmpty();

    T& operator [] (std::size_t index);

    void writeIntoFile(std::string fileName);
    void readFromFile(std::string fileName);
};

template <class T>
List<T>::List()
{  
    try
    {
        this->data = new T[INITIAL_CAPACITY];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }
    
    this->size = 0;
    this->capacity = INITIAL_CAPACITY;
}

template <class T>
void List<T>::copy(const List& other)
{
    T* buffer = nullptr;
    try
    {
        buffer = new T[other.capacity];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (std::size_t i = 0; i < other.size; ++i)
    {
        buffer[i] = other.data[i];
    }

    this->data = buffer;
    this->size = other.size;
    this->capacity = other.capacity;    
}

template <class T>
void List<T>::deallocate()
{
    if (this->data)
    {
        delete[] this->data;
    }
}

template <class T>
void List<T>::resize()
{
    T* buffer = nullptr;
    try
    {
        buffer = new T[this->capacity*INCREASE_STEP];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (std::size_t i = 0; i < this->size; ++i)
    {
        buffer[i] = this->data[i];
    }

    this->deallocate();
    this->data = buffer;
    this->capacity *= INCREASE_STEP;    
}

template <class T>
List<T>::List(const List<T>& other)
{
    this->copy(other);
}

template <class T>
List<T>& List<T>::operator = (const List<T>& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }
}

template <class T>
List<T>::~List()
{
    this->deallocate();
}

template <class T>
bool List<T>::contains(T element)
{
    for (std::size_t i = 0; i < this->size; ++i)
    {
        if (element == this->data[i])
        {
            return true;
        }
    }

    return false;
}

template <class T>
void List<T>::push_back(T element)
{
    if (!this->contains(element))
    {
        if (this->size >= this->capacity)
        {
            this->resize();
        }

        this->data[this->size++] = element;
    }
}

template <class T>
void List<T>::removeAt(std::size_t index)
{
    if (index >= this->size)
    {
        throw std::out_of_range("Invalid index");
    }

    for (std::size_t i = index; i < this->size - 1; ++i)
    {
        this->data[i] = this->data[i + 1];
    }

    --this->size;
}

template <class T>
T& List<T>::operator [] (std::size_t index)
{
    if (index >= this->size)
    {
        throw std::out_of_range("Invalid index");
    }

    return this->data[index];
}

template <class T>
std::size_t List<T>::getSize()
{
    return this->size;
}

template <class T>
bool List<T>::isEmpty()
{
    return this->size == 0;
}

template <class T>
void List<T>::writeIntoFile(std::string fileName)
{
    std::ofstream file(fileName.c_str());

    if (!file.is_open())
    {
        throw std::invalid_argument("Problem while opening the file!");
    }

    for (std::size_t i = 0; i < this->size; ++i)
    {
        file << this->data[i] << std::endl;
    }

    file.close();
}

template <class T>
void List<T>::readFromFile(std::string fileName)
{
    std::ifstream file(fileName.c_str());

    if (!file.is_open())
    {
        throw std::invalid_argument("Problem while opening the file!");
    }

    while (!file.eof())
    {
        T temp;
        file >> temp;
        if (!file.eof())
        {
            this->push_back(temp);
        }
    }

    file.close();
}