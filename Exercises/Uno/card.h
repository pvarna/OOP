#pragma once
#include "enums.h"

const unsigned int DEFAULT_NUMBER = 0;
const Color DEFAULT_COLOR = Color::UNKNOWN;

const unsigned int REVERSE = 10;
const unsigned int PLUS_FOUR = 11;
const unsigned int CHANGE_COLOR = 12;
const unsigned int SKIP = 13;

const unsigned int MAX_NUMBER_CARD = 13;

class Card
{
private:
    unsigned int number;
    Color color;

public:
    Card(unsigned int number = DEFAULT_NUMBER, Color color = DEFAULT_COLOR);

    void generateRandom();

    void setColor(int color);

    unsigned int getNumber() const;
    Color getColor() const;

    bool operator == (const Card& other) const;

    friend std::ostream& operator << (std::ostream& out, const Card& card);
};