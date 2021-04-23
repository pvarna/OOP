#pragma once

#include "doctor.h"

class Dentist : public Doctor
{
public:
    Dentist(std::string name);
    void performSurgery();
};