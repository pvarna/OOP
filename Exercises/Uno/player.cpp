#include "player.h"

Player::Player(std::size_t handSize)
{
    if (handSize > MAX_CARDS_IN_HAND || handSize == 0)
    {
        throw std::invalid_argument("Invalid number of cards in hand");
    }

    for (std::size_t i = 0; i < handSize; ++i)
    {
        this->hand[i].generateRandom();
    }
    this->handSize = handSize;
}

std::size_t Player::getHandSize() const
{
    return this->handSize;
}

const Card& Player::getCard(std::size_t index) const
{
    if (index >= this->handSize)
    {
        throw std::invalid_argument("Invalid argument");
    }

    return this->hand[index];
}

bool Player::isThereFreeSpaceInHand()
{
    return this->handSize < MAX_CARDS_IN_HAND;   
}

std::size_t Player::chooseCard()
{
    std::cout << "Choose a card: ";
    std::size_t choice;
    do
    {
        std::cin >> choice;
        if (choice >= this->handSize)
        {
            std::cout << "Invalid index. Try again." << std::endl;
        }
    } while (choice >= this->handSize);
    
    return choice;
}

void Player::removeCard(const Card& card)
{
    int searchedIndex = -1;
    for (std::size_t i = 0; i < this->handSize; ++i)
    {
        if (card == this->hand[i])
        {
            searchedIndex = i;
        }
    }

    if (searchedIndex == -1)
    {
        std::cout << "Card not found!" << std::endl;
        return;
    }

    this->hand[searchedIndex] = this->hand[this->handSize - 1];
    --this->handSize;
}

void Player::drawCard(Deck& deck)
{
    if (!this->isThereFreeSpaceInHand())
    {
        this->removeCard(this->chooseCard());
    }
    this->hand[this->handSize++] = deck.topCard();
}

Card Player::playCard()
{
    std::size_t choice = this->chooseCard();
    Card result = this->hand[choice];

    return result;
}