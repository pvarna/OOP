#include "deck.h"

Deck::Deck(std::size_t size)
{
    if (size < MIN_DECK_SIZE)
    {
        throw std::invalid_argument("Invalid deck size");
    }

    this->size = size;
    this->currentIndex = this->size - 1;

    this->deck = nullptr;
    try
    {
        this->deck = new Card[size];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }

    while (this->deck[this->currentIndex].getNumber() > 9)
    {
        this->deck[this->currentIndex].generateRandom();
    }
}

void Deck::copy(const Deck& other)
{
    Card* buffer = nullptr;
    try
    {
        buffer = new Card[other.size];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    for (std::size_t i = 0; i < other.size; ++i)
    {
        buffer[i] = other.deck[i];
    }

    if (this->deck)
    {
        delete[] this->deck;
    }
    this->deck = buffer;
    this->size = other.size;
    this->currentIndex = other.currentIndex;    
}

void Deck::deallocate()
{
    if (this->deck)
    {
        delete[] this->deck;
    }
}

Deck::Deck(const Deck& other)
{
    this->copy(other);
}

Deck& Deck::operator = (const Deck& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}

Deck::~Deck()
{
    this->deallocate();
}

Card& Deck::operator [] (std::size_t index)
{
    if (index >= this->size)
    {
        throw std::invalid_argument("Invalid index");
    }

    return this->deck[index];
}

const Card& Deck::operator [] (std::size_t index) const
{
    if (index >= this->size)
    {
        throw std::invalid_argument("Invalid index");
    }

    return this->deck[index];
}

std::size_t Deck::getSize() const
{
    return this->size;
}

const Card& Deck::topCard()
{
    return this->deck[this->currentIndex--];
}