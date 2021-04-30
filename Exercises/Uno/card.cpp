#include <iostream>
#include <cstdlib>
#include "card.h"

Card::Card(unsigned int number, Color color)
{
    if (number > MAX_NUMBER_CARD)
    {
        throw std::invalid_argument("Invalid number");
    }

    this->number = number;
    this->color = color;

    if (number == DEFAULT_NUMBER || color == DEFAULT_COLOR)
    {
        this->generateRandom();
    }
}

void Card::generateRandom()
{
    this->number = rand() % 13 + 1;
    int color = rand() % 4;

    this->setColor(color);
}

void Card::setColor(int color)
{
    switch (color)
    {
    case 0:
        this->color = Color::RED;
        break;
    case 1:
        this->color = Color::BLUE;
        break;
    case 2:
        this->color = Color::YELLOW;
        break;
    case 3:
        this->color = Color::GREEN;
        break;
    default:
        this->color = Color::UNKNOWN;
        break;
    }
}

unsigned int Card::getNumber() const
{
    return this->number;
}

Color Card::getColor() const
{
    return this->color;
}

std::ostream& operator << (std::ostream& out, const Card& card)
{
    out << "|| ";

    switch (card.color)
    {
    case Color::RED:
        out << "Red ";
        break;
    case Color::BLUE:
        out << "Blue ";
        break;
    case Color::GREEN:
        out << "Green ";
        break;
    case Color::YELLOW:
        out << "Yellow ";
        break;
    }

    switch (card.number)
    {
    case REVERSE:
        out << "Reverse ||";  
        break;
    case PLUS_FOUR:
        out << "+4 ||";
        break;
    case CHANGE_COLOR:
        out << "Change color ||";
        break;
    case SKIP:
        out << "Skip ||";
        break;
    default:
        out << card.number << " ||";
        break;
    }

    return out;
}

bool Card::operator == (const Card& other) const
{
    return this->number == other.number && this->color == other.color;
}