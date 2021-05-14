#pragma once

#include "list.h"

template <class T>
class Order : public List<T>
{
public:
    Order();

    void push_back(T element);
};

template <class T>
Order<T>::Order() : List<T>() {}

template <class T>
void Order<T>::push_back(T element)
{
    if (!this->contains(element))
    {
        if (this->size >= this->capacity)
        {
            this->resize();
        }

        std::size_t i = this->size;

        while (i > 0 && this->data[i-1] > element)
        {
            this->data[i] = this->data[i-1];
            --i;
        }

        this->data[i] = element;

        ++this->size;
    }

}