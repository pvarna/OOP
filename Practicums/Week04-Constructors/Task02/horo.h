#pragma once

enum Region
{
    Severnyashki,
    Dobrudzhanski,
    Strandzhanski,
    Trakiiski,
    Rodopski,
    Pirinski,
    Shopski
};

class Horo
{
private:
    char* name;
    char* tact;
    Region region;

public:
    Horo(const char* name, const char* tact, const Region region);

    char* getName() const;
    char* getTact() const;
    Region getRegion() const;

    void print();

    ~Horo();
};