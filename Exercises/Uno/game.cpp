#include <iostream>
#include "game.h"

Game::Game(std::size_t countOfPlayers, std::size_t mainDeckSize)
        : mainDeck(mainDeckSize), deckOnTheField(mainDeckSize)
{
    if (countOfPlayers < DEFAULT_NUMBER_OF_PLAYERS)
    {
        throw std::invalid_argument("Invalid number of players");
    }

    if (mainDeckSize < MIN_DECK_SIZE)
    {
        throw std::invalid_argument("Invalid deck size");
    }

    this->players = nullptr;
    try
    {
        this->players = new Player[countOfPlayers];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(1);
    }

    this->countOfPlayers = countOfPlayers;
    this->currentCardOnField = mainDeckSize - 1;
    this->isReverse = false;
}

Game::~Game()
{
    if (this->players)
    {
        delete[] this->players;
    }
}

Player& Game::getPlayer(std::size_t index)
{
    if (index >= this->countOfPlayers)
    {
        throw std::invalid_argument("Invalid index");
    }

    return this->players[index];
}

bool Game::canCardBePlayed(const Card& card) const
{
    return (card.getNumber() == CHANGE_COLOR || card.getNumber() == PLUS_FOUR) ||
           (this->deckOnTheField[this->currentCardOnField].getNumber() == card.getNumber()) ||
           (this->deckOnTheField[this->currentCardOnField].getColor() == card.getColor());
}

void Game::changeColor(Card& card)
{
    std::size_t choice;
    do
    {
        std::cout << "Please choose a color:" << std::endl;
        std::cout << "0. Red" << std::endl;
        std::cout << "1. Blue" << std::endl;
        std::cout << "2. Yellow" << std::endl;
        std::cout << "3. Green" << std::endl;

        std::cin >> choice;
        if (choice > 3)
        {
            std::cout << "Invalid choice. Try again!" << std::endl;
        }
    } while (choice > 3);
    
    card.setColor(choice);
}

std::size_t Game::specialCard(Card& card, std::size_t index)
{
    if (card.getNumber() == REVERSE)
    {
        this->isReverse = !this->isReverse;
    }
    else if (card.getNumber() == PLUS_FOUR)
    {
        index = this->getNextPlayer(index);
        for (std::size_t i = 0; i < 4; ++i)
        {
            this->swapDecksIfNeeded();
            this->players[index].drawCard(this->mainDeck);
        }
        this->changeColor(card);
        return index;
    }
    else if (card.getNumber() == CHANGE_COLOR)
    {
        this->changeColor(card);
    }
    else if (card.getNumber() == SKIP)
    {
        index = this->getNextPlayer(index);
    }

    return this->getNextPlayer(index);
}

bool Game::hasPlayableCards(const Player& player)
{
    for (std::size_t i = 0; i < player.getHandSize(); ++i)
    {
        if (canCardBePlayed(player.getCard(i)))
        {
            return true;
        }
    }

    return false;
}

void Game::swapDecksIfNeeded()
{
    if (this->currentCardOnField < 0)
    {
        this->mainDeck = this->deckOnTheField;
        this->currentCardOnField = this->mainDeck.getSize() - 1;
        this->deckOnTheField = Deck(this->mainDeck.getSize());
    }
}

std::size_t Game::getNextPlayer(std::size_t index)
{
    if (this->isReverse)
    {
        if (index == 0)
        {
            return this->countOfPlayers - 1;
        }
        return index - 1;
    }

    if (index + 1 >= this->countOfPlayers)
    {
        return 0;
    }
    return index + 1;
}

void Game::printGame(const Player& player)
{
    std::cout << "Current card on the field: " << this->deckOnTheField[this->currentCardOnField] << std::endl;
    for (std::size_t i = 0; i < player.getHandSize(); ++i)
    {
        std::cout << "Card #" << i  << ": " << player.getCard(i) << std::endl;
    }
}

void Game::turn(Player& player, std::size_t& index, bool& isWinner)
{
    this->swapDecksIfNeeded();
    if (!hasPlayableCards(player))
    {
        player.drawCard(this->mainDeck);
        std::cout << "You cannot play any cards. You drew: " << player.getCard(player.getHandSize() - 1) << std::endl;
        index = this->getNextPlayer(index);
        isWinner = false;
        return;
    }

    Card choice;
    do
    {
        choice = player.playCard();
        if (!this->canCardBePlayed(choice))
        {
            std::cout << "You cannot play this card. Try again!" << std::endl;
        }
    } while (!this->canCardBePlayed(choice));
    this->deckOnTheField[this->currentCardOnField - 1] = choice;
    --this->currentCardOnField;
    player.removeCard(choice);
    if (player.getHandSize() == 0)
    {
        isWinner = true;
        return;
    }

    index = specialCard(this->deckOnTheField[this->currentCardOnField], index);
    isWinner = false;
}

void Game::play()
{
    std::size_t currentPlayer = 0;
    std::size_t winner;
    while (true)
    {
        this->printGame(this->getPlayer(currentPlayer));
        std::cout << "Player " << currentPlayer << "'s turn" << std::endl;
        bool isWinner = false;
        this->turn(this->getPlayer(currentPlayer), currentPlayer, isWinner);
        if (isWinner)
        {
            winner = currentPlayer;
            break;
        }
    }

    std::cout << "Player " << winner << " wins!!!" << std::endl;
}