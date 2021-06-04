#include "furnitureHouse.h"
#include <iostream>

int main ()
{
    Furniture* furniture = nullptr;

    std::cout << "What kind of furniture you want to add?" << std::endl;
    std::cout << "1. Table" << std::endl;
    std::cout << "2. Chair" << std::endl;
    std::cout << "3. Bed" << std::endl;
    std::cout << "Enter your choice: ";

    unsigned int choice;
    std::cin >> choice;
    std::cin.ignore();

    double height;
    double width;
    double length;
    std::size_t quantity;
    double price;

    std::cout << "Enter height: ";
    std::cin >> height;
    std::cout << "Enter width: ";
    std::cin >> width;
    std::cout << "Enter length: ";
    std::cin >> length;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    std::cout << "Enter price: ";
    std::cin >> price;

    switch (choice)
    {
    case 1:
        std::cout << "What kind of table you want to add?" << std::endl;
        std::cout << "1. Living room table" << std::endl;
        std::cout << "2. Kithen table" << std::endl;

        unsigned int tableChoice;
        std::cin >> tableChoice;
        std::cin.ignore();

        if (tableChoice > 2)
        {
            throw std::invalid_argument("Invalid table");
        }

        TableType tableType = (tableChoice == 1) ? TableType::LIVING_ROOM : TableType::KITCHEN;

        furniture = new Table(height, width, length, quantity, price, tableType);

        break;

    case 2:
        std::cout << "What kind of chair you want to add?" << std::endl;
        std::cout << "1. Wooden chair" << std::endl;
        std::cout << "2. Plastic chair" << std::endl;
        std::cout << "3. Metal chair" << std::endl;

        unsigned int chairChoice;
        std::cin >> chairChoice;
        std::cin.ignore();

        ChairType chairType;

        switch (chairChoice)
        {
        case 1:
            chairType = ChairType::WOODEN;
            break;
        case 2:
            chairType = ChairType::PLASTIC;
            break;
        case 3:
            chairType = ChairType::METAL;
            break;
        default:
            throw std::invalid_argument("Invalid chair");
        }

        furniture = new Chair(height, width, length, quantity, price, chairType);
        break;

    case 3:
        furniture = new Bed(height, width, length, quantity, price);

        break;

    default:
        throw std::invalid_argument("Invalid furniture");
    }
}