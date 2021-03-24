#pragma once
//#include <iostream>

class Person
{
private:
    char* name;
    int age;
    bool hasDriveLicense;
    
public:
    Person();
    Person(const char* _name, const int _age, const bool _hasDriveLicense);
    Person(const Person& person);

    char* getName() const;
    int getAge() const;
    bool getHasDriveLicense() const;

    void setName(const char* _name);
    void setAge(const int _age);
    void setHasDriveLicense(const bool _hasDriveLicense);

    void print();

    Person& operator = (const Person& person);
    friend std::ostream& operator << (std::ostream& out, const Person& person);
    friend std::istream& operator >> (std::istream& in, Person& person); 

    ~Person();
};

