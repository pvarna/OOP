#pragma once

#include <cstddef>
#include "player.h"

const std::size_t DEFAULT_NUMBER_OF_PLAYERS = 2;

class Game
{
private:
    Player* players;
    std::size_t countOfPlayers;
    Deck mainDeck;
    Deck deckOnTheField;
    int currentCardOnField;
    bool isReverse;

public:
    Game(std::size_t countOfPlayers = DEFAULT_NUMBER_OF_PLAYERS, std::size_t mainDeckSize = DEFAULT_DECK_SIZE);
    Game(const Game& other) = delete;
    Game& operator = (const Game& other) = delete;
    ~Game();

    Player& getPlayer(std::size_t index);

    void swapDecksIfNeeded();
    std::size_t getNextPlayer(std::size_t index);
    bool canCardBePlayed(const Card& card) const;
    void changeColor(Card& card);
    std::size_t specialCard(Card& card, std::size_t index);
    bool hasPlayableCards(const Player& player);
    void printGame(const Player& player);
    void turn(Player& player, std::size_t& index, bool& isWinner);

    void play();
};