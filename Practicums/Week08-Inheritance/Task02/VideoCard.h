#pragma once

#include <string>
#include "Component.h"

class VideoCard : public Component
{
private:
    std::string name;

public:
    VideoCard(std::string name);

    void print();
};