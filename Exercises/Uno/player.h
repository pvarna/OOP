#pragma once

#include <cstddef>
#include "deck.h"

const std::size_t MAX_CARDS_IN_HAND = 10;
const std::size_t DEFAULT_CARDS_IN_HAND = 3;

class Player
{
private:
    Card hand[MAX_CARDS_IN_HAND];
    std::size_t handSize;

public:
    Player(std::size_t handSize = DEFAULT_CARDS_IN_HAND);

    std::size_t getHandSize() const;
    const Card& getCard(std::size_t index) const;

    bool isThereFreeSpaceInHand();
    std::size_t chooseCard();
    void removeCard(const Card& card);
    void drawCard(Deck& deck);
    Card playCard();
};