#pragma once

#include "furniture.h"
#include "chair.h"
#include "table.h"
#include "bed.h"
#include <vector>

class FurnitureHouse
{
private:
    std::vector<Furniture*> furniture;

public:
    FurnitureHouse();
    FurnitureHouse(const FurnitureHouse& other) = delete;
    FurnitureHouse& operator = (const FurnitureHouse& other) = delete;
    ~FurnitureHouse();

    void addNewFurniture(Furniture* furniture);
    void removeFurniture(unsigned int id);

    void showInfo(unsigned int id);
};