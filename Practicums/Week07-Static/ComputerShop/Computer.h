#pragma once

#include <string>

class Computer
{
private:
    static int counter;
    int serialNumber;
    std::string brand;
    std::string processor;
    std::string video;
    int hardDrive;
    double weight;
    double batteryLife;
    double price;
    int quantity;

public:
    Computer();
    Computer(std::string brand, std::string processor, std::string video, 
            int hardDrive, double weight, double batteryLife, double price);
    
    int getSerialNumber() const;
    std::string getBrand() const;
    std::string getProcessor() const;
    std::string getVideo() const;
    int getHardDrive() const;
    double getWeight() const;
    double getBatteryLife() const;
    double getPrice() const;
    int getQuantity() const;

    void setBrand(std::string brand);
    void setProcessor(std::string processor);
    void setVideo(std::string video);
    void setHardDrive(int hardDrive);
    void setWeight(double weight);
    void setBaterryLife(double batteryLife);
    void setPrice(double price);

    void increaseQuantity();
    void decreaseQuantity();

    friend std::ostream& operator << (std::ostream& out, const Computer& computer);
};