#include <iostream>
#include "surgeon.h"
#include "dentist.h"

int main ()
{
    Surgeon surgeon("Dr. Petrov");
    Dentist dentist("Dr. Kolev");

    surgeon.performSurgery();
    dentist.performSurgery();

    return 0;
}