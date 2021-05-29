#include <iostream>
#include <fstream>

struct Student
{
    char name[30] = "unknown";
    unsigned int fn = 0;
};

std::size_t getFileSize(std::ifstream &ifs)
{
    std::size_t current = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    
    std::size_t result = ifs.tellg();
    ifs.seekg(current, std::ios::beg);

    return result;
}

bool writeStudents(const char* path)
{
    std::ofstream file(path, std::ios::binary | std::ios::trunc);
    if (!file.is_open())
    {
        return false;
    }

    Student students[] = {
        {"Pesho", 82214},
        {"Mirelian", 88588},
        {"Kate", 87653},
        {"Kaloyan", 34567}
    };

    //file.write((const char*) students, sizeof(students));

    for (std::size_t i = 0; i < 4; ++i)
    {
        file.write((const char*) &students[i], sizeof(Student));
    }

    file.close();
    return true;
}

bool readStudents(const char* path)
{
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open())
    {
        return false;
    }

    std::size_t fileSize = getFileSize(file);
    if (fileSize == 0)
    {
        return false;
    }

    std::size_t countOfStudents = fileSize / sizeof(Student);
    Student* students = new Student[countOfStudents];

    //file.read((char *) students, fileSize);
    for (std::size_t i = 0; i < countOfStudents; ++i)
    {
        file.read((char *) &students[i], sizeof(Student));
    }

    for (std::size_t i = 0; i < countOfStudents; ++i)
    {
        std::cout << students[i].name << " " << students[i].fn << std::endl;
    }

    file.close();

    return true;
}

bool writeNumbersIntoFile(const char* path)
{
    std::ofstream file(path, std::ios::binary);
    if (!file.is_open())
    {
        return false;
    }

    std::cout << "Enter how many numbers you want to write: ";
    unsigned int count;
    std::cin >> count;
    for (std::size_t i = 0; i < count; ++i)
    {
        int temp;
        std::cin >> temp;
        file.write((const char*) &temp, sizeof(int));
    }

    file.close();

    return true;
}

bool readNumbersFromFile(const char* path)
{
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open())
    {
        return false;
    }

    std::size_t sizeFile = getFileSize(file);
    std::size_t numberOfNumbers = sizeFile / sizeof(int);

    int* numbers = new int[numberOfNumbers];
    for (std::size_t i = 0; i < numberOfNumbers; ++i)
    {
        file.read((char *) &numbers[i], sizeof(int));
    }

    for (std::size_t i = 0; i < numberOfNumbers; ++i)
    {
        std::cout << numbers[i] << std::endl;
    }

    file.close();

    return true;
}

int main ()
{
    /*if (writeStudents("students.bin"))
    {
        std::cout << "Successfully written" << std::endl;
    }
    else
    {
        std::cout << "Error while writing" << std::endl;
    }

    if (!readStudents("students.bin"))
    {
        std::cout << "error while reading";
    }*/

    if (writeNumbersIntoFile("numbers.dat"))
    {
        std::cout << "Successfully written" << std::endl;
    }
    else
    {
        std::cout << "Error while writing" << std::endl;
    }

    if (!readNumbersFromFile("numbers.dat"))
    {
        std::cout << "error while reading";
    }

    return 0;
}