#include <iostream>
#include <cstring>
#include "student.h"
#include "teacher.h"
#include "sorting.h"
#include "university.h"

/*template <typename T>
using sortingFunctions = bool (*) (T, T);

template <typename T>
void sortAllTypes(T* people, sortingFunctions<T> sortingFunction, size_t size);

template <typename T>
bool nameSortAsc(T first, T second);
template <typename T>
bool nameSortDesc(T first, T second);

bool nameSortAsc(Student first, Student second);
bool nameSortDesc(Student first, Student second);

bool fnSortAsc(Student first, Student second);
bool fnSortDesc(Student first, Student second);

bool averageScoreSortAsc(Student first, Student second);
bool averageScoreSortDesc(Student first, Student second);*/

int main()
{
    size_t numberStudents, numberTeachers;

    std::cout << "Please enter the number of students: ";
    std::cin >> numberStudents;
    std::cin.ignore();

    Student* students = new(std::nothrow) Student[numberStudents];
    if (!students)
    {
        std::cout << "Memory problem!" << std::endl;
        return 1;
    }

    for (int i = 0; i < numberStudents; ++i)
    {
        Student currentStudent;
        std::cout << "Student #" << i + 1 << std::endl;
        currentStudent.input();
        currentStudent.copyStudent(students[i]);
    }

    std::cout << "Please enter the number of teachers: ";
    std::cin >> numberTeachers;
    std::cin.ignore();

    Teacher* teachers = new(std::nothrow) Teacher[numberTeachers];
    if (!teachers)
    {
        std::cout << "Memory problem!" << std::endl;
        return 1;
    }

    for (int i = 0; i < numberTeachers; ++i)
    {
        Teacher currentTeacher;
        std::cout << "Teacher #" << i + 1 << std::endl;
        currentTeacher.input();
        currentTeacher.copyTeacher(teachers[i]);
    }


    University university;
    university.createStudents(students, numberStudents);
    university.createTeachers(teachers, numberTeachers);

    std::cout << "Students without sorting: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    std::cout << "Teachers without sorting: " << std::endl;
    university.printAllTeachers();

    std::cout << std::endl;

    university.sort(name, asc);

    //sortAllTypes(university.listOfStudents, nameSortAsc, numberStudents);

    //sortAllTypes<Student>(university.listOfStudents, nameSortAsc<Student>, numberStudents);
    //sortAllTypes<Teacher>(university.listOfTeachers, nameSortAsc<Teacher>, numberTeachers);

    //university.sort<Student>(university.listOfStudents, name, asc, numberStudents);
    //university.sort<Teacher>(university.listOfTeachers, name, asc, numberStudents);

    std::cout << "Students sorted ascending per name: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    /*std::cout << "Teachers sorted descending per name: " << std::endl;
    university.printAllTeachers();

    std::cout << std::endl;*/

    //sortAllTypes<Student>(university.listOfStudents, nameSortDesc<Student>, numberStudents);
    //sortAllTypes<Teacher>(university.listOfTeachers, nameSortDesc<Teacher>, numberTeachers);

    //university.sort<Student>(university.listOfStudents, name, desc, numberStudents);
    //university.sort<Teacher>(university.listOfTeachers, name, desc, numberTeachers);

    //sortAllTypes(university.listOfStudents, nameSortDesc, numberStudents);

    university.sort(name, desc);

    std::cout << "Students sorted descending per name: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    /*std::cout << "Teachers sorted descending per name: " << std::endl;
    university.printAllTeachers();

    std::cout << std::endl;*/

    //sortAllTypes<Student>(university.listOfStudents, fnSortAsc, numberStudents);

    //university.sort<Student>(university.listOfStudents, fn, asc, numberStudents);

    //sortAllTypes(university.listOfStudents, fnSortAsc, numberStudents);

    university.sort(fn, asc);

    std::cout << "Students sorted ascending per FN: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    //sortAllTypes<Student>(university.listOfStudents, fnSortDesc, numberStudents);

    //university.sort<Student>(university.listOfStudents, fn, desc, numberStudents);

    //sortAllTypes(university.listOfStudents, fnSortDesc, numberStudents);

    university.sort(fn, desc);

    std::cout << "Students sorted descending per FN: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    //sortAllTypes<Student>(university.listOfStudents, averageScoreSortAsc, numberStudents);

    //university.sort<Student>(university.listOfStudents, averageScore, asc, numberStudents);

    //sortAllTypes(university.listOfStudents, averageScoreSortAsc, numberStudents);

    university.sort(averageScore, asc);

    std::cout << "Students sorted ascending per average score: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    //sortAllTypes<Student>(university.listOfStudents, averageScoreSortDesc, numberStudents);

    //university.sort<Student>(university.listOfStudents, averageScore, desc, numberStudents);

    //sortAllTypes(university.listOfStudents, averageScoreSortDesc, numberStudents);

    university.sort(averageScore, desc);

    std::cout << "Students sorted descending per average score: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;


    for (int i = 0; i < numberStudents; ++i)
    {
        students[i].deallocateMemory();
    }
    delete[] students;

    for (int i = 0; i < numberTeachers; ++i)
    {
        teachers[i].deallocateMemory();
    }
    delete[] teachers;

    return 0;
}

/*template <typename T>
void sortAllTypes(T* people, sortingFunctions<T> sortingFunction, size_t size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
            if(sortingFunction(people[i], people[j]))
            {
                T temp = people[j];
                people[j] = people[i];
                people[i] = temp;
            }
        }
    }
}

template <typename T>
bool nameSortAsc(T first, T second)
{
    return strcmp(first.getName(), second.getName()) > 0;
}

template <typename T>
bool nameSortDesc(T first, T second)
{
    return strcmp(first.getName(), second.getName()) < 0;
}

bool fnSortAsc(Student first, Student second)
{
    return strcmp(first.getFN(), second.getFN()) > 0;
}

bool fnSortDesc(Student first, Student second)
{
    return strcmp(first.getFN(), second.getFN()) < 0;
}

bool averageScoreSortAsc(Student first, Student second)
{
    return first.getAverageGrade() > second.getAverageGrade();
}

bool averageScoreSortDesc(Student first, Student second)
{
    return first.getAverageGrade() < second.getAverageGrade();
}*/