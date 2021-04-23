#include <iostream>
#include "student.h"

int main ()
{
    Human human1("Mitko", "Velkov", 20);
    Student student1("Pesho", "Kolev", 19, "KN"), student2("Misho", "Enev", 19, "IS");

    human1.print();
    student1.print();
    student2.print();

    return 0;
}