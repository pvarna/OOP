#pragma once

class Food
{
protected:
    static unsigned int counter;
    unsigned int id;
    double weight;
    unsigned int pieces;
    double weightPerPiece;
    double price;

public:
    Food(double weight, unsigned int pieces, double price);

    void consume();
    void print();

    unsigned int getId();
    double getPrice();
};