#include "student.h"
#include "teacher.h"
#include "university.h"

int main()
{
    size_t numberStudents, numberTeachers;

    std::cout << "Please enter the number of students: ";
    std::cin >> numberStudents;
    std::cin.ignore();

    Student* myStudents = new(std::nothrow) Student[numberStudents];
    if (!myStudents)
    {
        std::cout << "Memory problem!" << std::endl;
        return 1;
    }

    for (int i = 0; i < numberStudents; ++i)
    {
        Student currentStudent;
        std::cout << "Student #" << i + 1 << std::endl;
        currentStudent.input();
        currentStudent.copyStudent(myStudents[i]);
    }

    std::cout << "Please enter the number of teachers: ";
    std::cin >> numberTeachers;
    std::cin.ignore();

    Teacher* myTeachers = new(std::nothrow) Teacher[numberTeachers];
    if (!myTeachers)
    {
        std::cout << "Memory problem!" << std::endl;
        return 1;
    }

    for (int i = 0; i < numberTeachers; ++i)
    {
        Teacher currentTeacher;
        std::cout << "Teacher #" << i + 1 << std::endl;
        currentTeacher.input();
        currentTeacher.copyTeacher(myTeachers[i]);
    }


    University university;
    university.createStudents(myStudents, numberStudents);
    university.createTeachers(myTeachers, numberTeachers);

    std::cout << "Students without sorting: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    std::cout << "Teachers without sorting: " << std::endl;
    university.printAllTeachers();

    std::cout << std::endl;

    university.sort(name, asc, students);

    std::cout << "Students sorted ascending per name: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    university.sort(name, desc, students);

    std::cout << "Students sorted descending per name: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    university.sort(name, asc, teachers);

    std::cout << "Teachers sorted ascending per name: " << std::endl;
    university.printAllTeachers();

    std::cout << std::endl;

    university.sort(name, desc, teachers);

    std::cout << "Teachers sorted descending per name: " << std::endl;
    university.printAllTeachers();

    std::cout << std::endl;

    university.sort(fn, asc, students);

    std::cout << "Students sorted ascending per FN: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    university.sort(fn, desc, students);

    std::cout << "Students sorted descending per FN: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    university.sort(averageScore, asc, students);

    std::cout << "Students sorted ascending per average score: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;

    university.sort(averageScore, desc, students);

    std::cout << "Students sorted descending per average score: " << std::endl;
    university.printAllStudents();

    std::cout << std::endl;


    for (int i = 0; i < numberStudents; ++i)
    {
        myStudents[i].deallocateMemory();
    }
    delete[] myStudents;

    for (int i = 0; i < numberTeachers; ++i)
    {
        myTeachers[i].deallocateMemory();
    }
    delete[] myTeachers;

    return 0;
}