#include <iostream>
#include "Computer.h"

int Computer::counter = 0;

Computer::Computer() : brand(), processor(), video()
{
    this->serialNumber = counter++;
    this->hardDrive = 0;
    this->weight = 0.0;
    this->batteryLife = 0.0;
    this->price = 0.0;
    this->quantity = 1;
}

Computer::Computer(std::string brand, std::string processor, std::string video, 
        int hardDrive, double weight, double batteryLife, double price)
        : brand(brand), processor(processor), video(video)
{
    this->serialNumber = counter++;
    this->hardDrive = hardDrive;
    this->weight = weight;
    this->batteryLife = batteryLife;
    this->price = price;
    this->quantity = 1;
}

int Computer::getSerialNumber() const
{
    return this->serialNumber;
}

std::string Computer::getBrand() const
{
    return this->brand;
}

std::string Computer::getProcessor() const
{
    return this->processor;
}

std::string Computer::getVideo() const
{
    return this->video;
}

int Computer::getHardDrive() const
{
    return this->hardDrive;
}

double Computer::getWeight() const
{
    return this->weight;
}

double Computer::getBatteryLife() const
{
    return this->batteryLife;
}

double Computer::getPrice() const
{
    return this->price;
}

int Computer::getQuantity() const
{
    return this->quantity;
}

void Computer::setBrand(std::string brand)
{
    this->brand = brand;
}

void Computer::setProcessor(std::string processor)
{
    this->processor = processor;
}

void Computer::setVideo(std::string video)
{
    this->video = video;
}

void Computer::setHardDrive(int hardDrive)
{
    this->hardDrive = hardDrive;
}

void Computer::setWeight(double weight)
{
    this->weight = weight;
}

void Computer::setBaterryLife(double batteryLife)
{
    this->batteryLife = batteryLife;
}

void Computer::setPrice(double price)
{
    this->price = price;
}

void Computer::increaseQuantity()
{
    ++this->quantity;
}

void Computer::decreaseQuantity()
{
    --this->quantity;
}

std::ostream& operator << (std::ostream& out, const Computer& computer)
{
    out << "Brand: " << computer.brand << std::endl;
    out << "Quantity: " << computer.quantity;

    return out;
}