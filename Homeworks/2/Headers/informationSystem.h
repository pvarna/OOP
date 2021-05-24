#pragma once

#include "data.h"
#include "commandLine.h"

class InformationSystem
{
private:
    Data data;
    CommandLine* cmd;

    void printHelp();

public:
    InformationSystem();
    InformationSystem(const InformationSystem& other) = delete;
    InformationSystem& operator = (const InformationSystem& other) = delete;
    ~InformationSystem();

    void loadDataFromFile(const char* fileName);
    void start();
};