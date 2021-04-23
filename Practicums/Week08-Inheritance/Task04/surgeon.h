#pragma once

#include "doctor.h"

class Surgeon : public Doctor
{
public:
    Surgeon(std::string name);
    void performSurgery();
};