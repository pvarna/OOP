#include <iostream>
#include "person.h"
#include "car.h"

int main ()
{
    Person mime("Mimeto", 19, true);

    Car kolataNaMimeto(mime, "renault", "A 1234 ST", PURPLE);

    Car copyMimeKola(kolataNaMimeto);

    Car copy2MimeKola;
    copy2MimeKola = kolataNaMimeto;

    kolataNaMimeto.print();
    copyMimeKola.print();
    copy2MimeKola.print();

    return 0;
}