#pragma once

class Person
{
private:
    char* name;
    int age;
    bool hasDriveLicense;

    void copy(const Person& other);
    void deallocate();
    
public:
    Person();
    Person(const char* _name, const int _age, const bool _hasDriveLicense);
    Person(const Person& other);
    
    Person& operator = (const Person& other);

    char* getName() const;
    int getAge() const;
    bool getHasDriveLicense() const;

    void setName(const char* _name);
    void setAge(const int _age);
    void setHasDriveLicense(const bool _hasDriveLicense);

    void print();

    ~Person();
};

