#include <iostream>
#include "VideoCard.h"

VideoCard::VideoCard(std::string name) : Component()
{
    this->name = name;
}

void VideoCard::print()
{
    std::cout << "Video Card" << std::endl;
    Component::print();
    std::cout << "Name: " << this->name << std::endl;
}