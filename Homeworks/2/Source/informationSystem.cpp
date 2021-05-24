#include "../Headers/informationSystem.h"
#include <iostream>
#include <fstream>

InformationSystem::InformationSystem()
{
    this->cmd = nullptr;
}

InformationSystem::~InformationSystem()
{
    if (this->cmd)
    {
        delete this->cmd;
    }
}

void InformationSystem::loadDataFromFile(const char* fileName)
{
    std::ifstream file(fileName);

    if (!file.is_open())
    {
       std::cout << "Problem while opening the file! No data will be loaded!" << std::endl;
    }

    bool validCommand = true;
    std::string buffer;
    while(getline(file, buffer))
    {
        try
        {
            if (this->cmd)
            {
                delete this->cmd;
                this->cmd = nullptr;
            }
            this->cmd = new CommandLine(buffer);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what();
            std::cout << " Data on this line will not be loaded!" << std::endl;
            validCommand = false;
        }

        std::string mainCommand = cmd->getMainCommand();
        std::string secondArgument = cmd->getSecondArgument();
        std::string thirdArgument = cmd->getThirdArgument();

        if (mainCommand == "VEHICLE")
        {
            try
            {
                this->data.addNewVehicle(secondArgument, thirdArgument);
            }
            catch(const std::exception& e)
            {
                std::cout << e.what();
                std::cout << " Please try again: " << std::endl;
            }
        }
        else if (mainCommand == "PERSON")
        {
            try
            {
                this->data.addNewPerson(secondArgument, thirdArgument);
            }
            catch(const std::exception& e)
            {
                std::cout << e.what();
                std::cout << " Please try again: " << std::endl;
            }
        }
        else if (mainCommand == "ACQUIRE")
        {
            try
            {
                this->data.acquire(secondArgument, thirdArgument);
            }
            catch(const std::exception& e)
            {
                std::cout << e.what();
                std::cout << " Please try again: " << std::endl;
            }
        }
        else
        {
            std::cout << "Invalid line! Data on this line will not be loaded!" << std::endl;
        }
    }

    file.close();
}

void InformationSystem::printHelp()
{
    std::cout << "List of commands:" << std::endl;
    std::cout << "VEHICLE <registration> <description>" << std::endl;
    std::cout << "PERSON <name> <id>" << std::endl;
    std::cout << "ACQUIRE <owner-id> <vehicle-id>" << std::endl;
    std::cout << "RELEASE <owner-id> <vehicle-id>" << std::endl;
    std::cout << "REMOVE <what>" << std::endl;
    std::cout << "SAVE <path>" << std::endl;
    std::cout << "SHOW [PEOPLE|VEHICLES|<id>]" << std::endl;
    std::cout << "EXIT" << std::endl;
}

void InformationSystem::start()
{
    std::string commandLine;
    std::cout << ">";
    
    getline(std::cin, commandLine);
    bool validCommand = true;

    while (true)
    {
        try
        {
            if (this->cmd)
            {
                delete this->cmd;
                this->cmd = nullptr;
            }
            this->cmd = new CommandLine(commandLine);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what();
            std::cout << " Please try again: " << std::endl;
            validCommand = false;
        }

        if (validCommand)
        {
            std::string mainCommand = cmd->getMainCommand();
            std::string secondArgument = cmd->getSecondArgument();
            std::string thirdArgument = cmd->getThirdArgument();

            if (mainCommand == "VEHICLE")
            {
                try
                {
                    this->data.addNewVehicle(secondArgument, thirdArgument);
                }
                catch(const std::exception& e)
                {
                    std::cout << e.what();
                    std::cout << " Please try again: " << std::endl;
                }
            }
            else if (mainCommand == "PERSON")
            {
                try
                {
                    this->data.addNewPerson(secondArgument, thirdArgument);
                }
                catch(const std::exception& e)
                {
                    std::cout << e.what();
                    std::cout << " Please try again: " << std::endl;
                }
            }
            else if (mainCommand == "ACQUIRE")
            {
                try
                {
                    this->data.acquire(secondArgument, thirdArgument);
                }
                catch(const std::exception& e)
                {
                    std::cout << e.what();
                    std::cout << " Please try again: " << std::endl;
                }
            }
            else if (mainCommand == "RELEASE")
            {
                try
                {
                    this->data.release(secondArgument, thirdArgument);
                }
                catch(const std::exception& e)
                {
                    std::cout << e.what();
                    std::cout << " Please try again: " << std::endl;
                }
            }
            else if (mainCommand == "REMOVE")
            {
                try
                {
                    this->data.remove(secondArgument);
                }
                catch(const std::exception& e)
                {
                    std::cout << e.what();
                    std::cout << " Please try again: " << std::endl;
                }
            }
            else if (mainCommand == "SAVE")
            {
                try
                {
                    this->data.saveIntoFile(secondArgument);
                }
                catch(const std::exception& e)
                {
                    std::cout << e.what();
                    std::cout << " Please try again: " << std::endl;
                }
            }
            else if (mainCommand == "SHOW")
            {
                try
                {
                    this->data.show(secondArgument);
                }
                catch(const std::exception& e)
                {
                    std::cout << e.what();
                    std::cout << " Please try again: " << std::endl;
                }
            }
            else if (mainCommand == "HELP")
            {
                this->printHelp();
            }
            else if (mainCommand == "EXIT")
            {
                return;
            }
            else
            {
                std::cout << "Invalid command! Please try again: " << std::endl;
            }
        }

        std::cout << ">";
        getline(std::cin, commandLine);
        validCommand = true;
    }
}