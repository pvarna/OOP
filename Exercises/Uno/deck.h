#pragma once

#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "card.h"

const std::size_t DEFAULT_DECK_SIZE = 30;
const std::size_t MIN_DECK_SIZE = 5;

class Deck
{
private:
    Card* deck;
    std::size_t size;
    std::size_t currentIndex;

    void copy(const Deck& other);
    void deallocate();

public:
    Deck(std::size_t size = DEFAULT_DECK_SIZE);
    Deck(const Deck& other);
    Deck& operator = (const Deck& other);
    ~Deck();

    Card& operator [] (std::size_t index);
    const Card& operator [] (std::size_t index) const;

    std::size_t getSize() const;

    const Card& topCard();
};