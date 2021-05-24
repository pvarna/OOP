#include "../Headers/data.h"
#include <cstddef>
#include <stdexcept>
#include <cctype>
#include <iostream>
#include <fstream>

Data::Data() {}

Data::~Data()
{
    std::size_t sizeVehicles = this->vehicles.size();
    std::size_t sizePeople = this->people.size();

    for (std::size_t i = 0; i < sizeVehicles; ++i)
    {
        if (this->vehicles[i])
        {
            delete this->vehicles[i];
        }
    }

    for (std::size_t i = 0; i < sizePeople; ++i)
    {
        if (this->people[i])
        {
            delete this->people[i];
        }
    }
}

inline bool Data::isNumber(std::string string)
{
    std::size_t length = string.length();
    for (std::size_t i = 0; i < length; ++i)
    {
        if (!isdigit(string[i]))
        {
            return false;
        }
    }

    return true;
}

inline bool Data::fileExists(std::string fileName)
{
    std::ifstream file;
    file.open(fileName.c_str());

    return file.good();
}

std::size_t Data::getNumberOfVehicles() const
{
    return this->vehicles.size();
}

std::size_t Data::getNumberOfPeople() const
{
    return this->people.size();
}

Vehicle* Data::getVehicle(std::size_t index)
{
    if (index >= this->vehicles.size())
    {
        throw std::invalid_argument("Invalid index!");
    }

    return this->vehicles[index];
}

Person* Data::getPerson(std::size_t index)
{
    if (index >= this->people.size())
    {
        throw std::invalid_argument("Invalid index!");
    }

    return this->people[index];
}

void Data::addNewVehicle(std::string registration, std::string description)
{
    std::size_t sizeVehicles = this->vehicles.size();

    for (std::size_t i = 0; i < sizeVehicles; ++i)
    {
        if (registration == this->vehicles[i]->getRegistration())
        {
            throw std::invalid_argument("A vehicle with the same registration number has already been created!");
        }
    }

    try
    {
        this->vehicles.push_back(new Vehicle(registration, description));   
    }
    catch(const std::bad_alloc& ba)
    {
        std::cout << "Problem while allocating memory for the new vehicle!" << std::endl;
        return;
    }
}

void Data::addNewPerson(std::string name, std::string id)
{
    if (!isNumber(id))
    {
        throw std::invalid_argument("The id of the person must be a number!");
    }
    unsigned int personId = std::stoi(id);

    std::size_t sizePeople = this->people.size();

    for (std::size_t i = 0; i < sizePeople; ++i)
    {
        if (personId == this->people[i]->getId())
        {
            throw std::invalid_argument("A person with the same id has already been created!");           
        }
    }

    try
    {
        this->people.push_back(new Person(name, personId));
    }
    catch(const std::bad_alloc& ba)
    {
        std::cout << "Problem while allocating memory for the new person!" << std::endl;
        return;
    }
}

void Data::acquire(std::string ownerId, std::string vehicleId)
{
    if (!isNumber(ownerId))
    {
        throw std::invalid_argument("The id of the person must be a number!");
    }
    unsigned int personId = std::stoi(ownerId);

    std::size_t sizePeople = this->people.size();
    std::size_t sizeVehicles = this->vehicles.size();

    int searchedIndexPerson = -1;
    for (std::size_t i = 0; i < sizePeople; ++i)
    {
        if (personId == this->people[i]->getId())
        {
            searchedIndexPerson = i;
            break;
        }
    }

    if (searchedIndexPerson == -1)
    {
        throw std::invalid_argument("There is not a person with such id!");
    }

    int searchedIndexVehicle = -1;
    for (std::size_t i = 0; i < sizeVehicles; ++i)
    {
        if (vehicleId == this->vehicles[i]->getRegistration())
        {
            searchedIndexVehicle = i;
            break;
        }
    }

    if (searchedIndexVehicle == -1)
    {
        throw std::invalid_argument("There is not a vehicle with such registration!");
    }    

    this->people[searchedIndexPerson]->acquireNewVehicle(this->vehicles[searchedIndexVehicle]);
    this->vehicles[searchedIndexVehicle]->addOwner(this->people[searchedIndexPerson]);    
}

void Data::release(std::string ownerId, std::string vehicleId)
{
    if (!isNumber(ownerId))
    {
        throw std::invalid_argument("The id of the person must be a number!");
    }
    unsigned int personId = std::stoi(ownerId);

    std::size_t sizePeople = this->people.size();
    std::size_t sizeVehicles = this->vehicles.size();

    int searchedIndexPerson = -1;
    for (std::size_t i = 0; i < sizePeople; ++i)
    {
        if (personId == this->people[i]->getId())
        {
            searchedIndexPerson = i;
            break;
        }
    }

    if (searchedIndexPerson == -1)
    {
        throw std::invalid_argument("There is not a person with such id!");
    }

    int searchedIndexVehicle = -1;
    for (std::size_t i = 0; i < sizeVehicles; ++i)
    {
        if (vehicleId == this->vehicles[i]->getRegistration())
        {
            searchedIndexVehicle = i;
            break;
        }
    }

    if (searchedIndexVehicle == -1)
    {
        throw std::invalid_argument("There is not a vehicle with such registration!");
    }
    
    this->people[searchedIndexPerson]->releaseVehicle(this->vehicles[searchedIndexVehicle]);
    this->vehicles[searchedIndexVehicle]->removeOwner(this->people[searchedIndexPerson]);
}

void Data::remove(std::string what)
{
    int searchedIndex = -1;

    if (this->isNumber(what)) // if it is person's id
    {
        unsigned int ownerId = std::stoi(what); 
        std::size_t sizePeople = this->people.size();
        std::size_t sizeVehicles = this->vehicles.size();

        for (std::size_t i = 0; i < sizePeople; ++i)
        {
            if (ownerId == this->people[i]->getId())
            {
                searchedIndex = i;
                break;
            }
        }

        if (searchedIndex == -1)
        {
            std::cout << "There is not a person with such id!" << std::endl;
            return;
        }

        if (this->people[searchedIndex]->getNumberOfOwnedVehicles() > 0)
        {
            std::cout << "This person already has some vehicles. Are you sure you want to remove him/her? [Y/n]: ";
            char choice;
            do
            {
                std::cin >> choice;
                std::cin.ignore();
                if (tolower(choice) != 'y' && tolower(choice) != 'n')
                {
                    std::cout << "Invalid choice! Try again [Y/n]: ";
                }
            } while (tolower(choice) != 'y' && tolower(choice) != 'n');

            if (tolower(choice) == 'n')
            {
                return;
            }
            this->people[searchedIndex]->releaseAll();

            for (std::size_t i = 0; i < sizeVehicles; ++i)
            {
                if (this->vehicles[i]->getOwner() == this->people[searchedIndex])
                {
                    this->vehicles[i]->removeOwner(this->people[searchedIndex]);
                }
            }
        }
        if (this->people[searchedIndex])
        {
            delete this->people[searchedIndex];
            this->people[searchedIndex] = nullptr;
        }
        this->people.erase(this->people.begin() + searchedIndex);
    }

    else // if it is vehicle's registration
    {
        std::string vehicleId = what; 
        std::size_t sizePeople = this->people.size();
        std::size_t sizeVehicles = this->vehicles.size();

        for (std::size_t i = 0; i < sizeVehicles; ++i)
        {
            if (vehicleId == this->vehicles[i]->getRegistration())
            {
                searchedIndex = i;
                break;
            }
        }

        if (searchedIndex == -1)
        {
            std::cout << "There is not a vehicle with such registration!" << std::endl;
            return;
        }

        Person* owner = this->vehicles[searchedIndex]->getOwner();
        if (owner)
        {
            std::cout << "This vehicle is already owned by someone. Are you sure you want to remove it? [Y/n]: ";
            char choice;
            do
            {
                std::cin >> choice;
                std::cin.ignore();
                if (tolower(choice) != 'y' && tolower(choice) != 'n')
                {
                    std::cout << "Invalid choice! Try again [Y/n]: ";
                }
            } while (tolower(choice) != 'y' && tolower(choice) != 'n');

            if (tolower(choice) == 'n')
            {
                return;
            }
            this->vehicles[searchedIndex]->removeOwner(owner);

            for (std::size_t i = 0; i < sizePeople; ++i)
            {
                for (std::size_t j = 0; j < this->people[i]->getNumberOfOwnedVehicles(); ++j)
                {
                    if (this->people[i]->getVehicle(j) == this->vehicles[searchedIndex])
                    {
                        this->people[i]->releaseVehicle(this->vehicles[searchedIndex]);
                        break;
                    }
                }
            }
        }

        if (this->vehicles[searchedIndex])
        {
            delete this->vehicles[searchedIndex];
            this->vehicles[searchedIndex] = nullptr;
        }
        this->vehicles.erase(this->vehicles.begin() + searchedIndex);
    }
}

void Data::show(std::string what)
{
    std::size_t sizePeople = this->people.size();
    std::size_t sizeVehicles = this->vehicles.size();

    if (what == "PEOPLE")
    {
        for (std::size_t i = 0; i < sizePeople; ++i)
        {
            std::cout << *this->people[i] << std::endl;
            if (i != sizePeople - 1)
            {
                std::cout << std::endl;
            }
        }

        if (sizePeople == 0)
        {
            std::cout << "There are not any created people yet!" << std::endl;
        }    
    }
    else if (what == "VEHICLES")
    {
        for (std::size_t i = 0; i < sizeVehicles; ++i)
        {
            std::cout << *this->vehicles[i] << std::endl;
            if (i != sizeVehicles - 1)
            {
                std::cout << std::endl;
            }
        }

        if (sizeVehicles == 0)
        {
            std::cout << "There are not any created vehicles yet!" << std::endl;
        }
    }
    else if (isNumber(what))
    {
        unsigned int personId = std::stoi(what);

        for (std::size_t i = 0; i < sizePeople; ++i)
        {
            if (personId == this->people[i]->getId())
            {
                std::cout << *this->people[i] << std::endl;
                return;
            }
        }

        std::cout << "There is not a person with such id!" << std::endl;
    }
    else
    {
        std::string vehicleId = what;

        for (std::size_t i = 0; i < sizeVehicles; ++i)
        {
            if (vehicleId == this->vehicles[i]->getRegistration())
            {
                std::cout << *this->vehicles[i] << std::endl;
                return;
            }
        }

        std::cout << "There is not a vehicle with such registration!" << std::endl;
    }
}

void Data::saveIntoFile(std::string fileName)
{
    std::ofstream file;

    if (fileExists(fileName))
    {
        file.open(fileName.c_str());

        if (!file.is_open())
        {
            throw std::invalid_argument("Problem while opening the file!");
        }

        std::cout << "This file already exists. Are you sure you want to overwrite the data in the file? [Y/n]: ";
        char choice;
        do
        {
            std::cin >> choice;
            std::cin.ignore();
            if (tolower(choice) != 'y' && tolower(choice) != 'n')
            {
                std::cout << "Invalid choice! Try again [Y/n]: ";
            }
        } while (tolower(choice) != 'y' && tolower(choice) != 'n');

        if (tolower(choice) == 'n')
        {
            file.close();
            return;
        }
    }

    file.open(fileName.c_str());

    std::size_t sizePeople = this->people.size();
    std::size_t sizeVehicles = this->vehicles.size();

    for (std::size_t i = 0; i < sizeVehicles; ++i)
    {
        file << "VEHICLE " << this->vehicles[i]->getRegistration() << " \""; 
        file << this->vehicles[i]->getDescription() << "\"" << std::endl;
    }

    for (std::size_t i = 0; i < sizePeople; ++i)
    {
        file << "PERSON \"" << this->people[i]->getName() << "\" ";
        file << this->people[i]->getId() << std::endl;
    }

    for (std::size_t i = 0; i < sizePeople; ++i)
    {
        for (std::size_t j = 0; j < this->people[i]->getNumberOfOwnedVehicles(); ++j)
        {
            file << "ACQUIRE " << this->people[i]->getId() << " " << this->people[i]->getVehicle(j)->getRegistration() << std::endl;
        }
    }

    file.close();
}