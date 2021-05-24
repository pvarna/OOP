#include "../Headers/registration.h"
#include <stdexcept>
#include <cstring>

inline bool Registration::isCapitalLetter(char ch)
{
    return ch >= 'A' && ch <= 'Z';
}

inline bool Registration::isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

bool Registration::isRegistrationValid(const char* registration)
{
    std::size_t length = strlen(registration);

    return (length >= MIN_REGISTRATION_LENGTH && length <= MAX_REGISTRATION_LENGTH) &&
           (isCapitalLetter(registration[length - 1]) && isCapitalLetter(registration[length - 2])) &&
           (isDigit(registration[length - 3]) && isDigit(registration[length - 4])  &&
            isDigit(registration[length - 5]) && isDigit(registration[length - 6])) &&
            isCapitalLetter(registration[length - 7]) &&
           (length == MIN_REGISTRATION_LENGTH || isCapitalLetter(registration[length - 8]));
}

Registration::Registration(const char* registration)
{
    if (!this->isRegistrationValid(registration))
    {
        throw std::invalid_argument("Invalid registration number!");
    }

    std::size_t length = strlen(registration);
    strcpy(this->registration, registration);
    this->registration[length] = '\0';
}

const char* Registration::getRegistration() const
{
    return this->registration;
}

bool Registration::operator == (const Registration& other) const
{
    return strcmp(this->registration, other.getRegistration()) == 0;
}