#pragma once

#include <cstddef>

const std::size_t MIN_REGISTRATION_LENGTH = 7;
const std::size_t MAX_REGISTRATION_LENGTH = 8;

class Registration
{
private:
    char registration[MAX_REGISTRATION_LENGTH + 1];

    bool isCapitalLetter(char ch);
    bool isDigit(char ch);
    bool isRegistrationValid(const char* registration);

public:
    Registration(const char* registration);

    const char* getRegistration() const;

    bool operator == (const Registration& other) const;
};