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

    /*size_t numberStudents = 3, numberTeachers = 2;

    Student* myStudents = new Student[3];
    Student student1("Peter Kolev", "014611XXXX", "82214", 6, 5, 5, 6, 4);
    Student student2("Sonya Nikolova", "015027XXXX", "82213", 5, 6, 5, 5, 6);
    Student student3("Mihail Enev", "014611XXXX", "7....", 6, 5, 6, 5, 6);

    myStudents[0] = student1;
    myStudents[1] = student2;
    myStudents[2] = student3;

    Teacher* myTeachers = new Teacher[2];
    Teacher teacher1("Petar Armyanov", "KN");
    Teacher teacher2("Stefan Gerdzhikov", "IS");

    myTeachers[0] = teacher1;
    myTeachers[1] = teacher2;*/

    University<Student> university1;
    University<Teacher> university2;
    university1.createPeople(myStudents, numberStudents);
    university2.createPeople(myTeachers, numberTeachers);

    std::cout << "Students without sorting: " << std::endl;
    university1.printPeople();

    std::cout << std::endl;

    std::cout << "Teachers without sorting: " << std::endl;
    university2.printPeople();

    std::cout << std::endl;

    university1.sort(name, asc);

    std::cout << "Students sorted ascending per name: " << std::endl;
    university1.printPeople();

    std::cout << std::endl;

    university1.sort(name, desc);

    std::cout << "Students sorted descending per name: " << std::endl;
    university1.printPeople();

    std::cout << std::endl;

    university2.sort(name, asc);

    std::cout << "Teachers sorted ascending per name: " << std::endl;
    university2.printPeople();

    std::cout << std::endl;

    university2.sort(name, desc);

    std::cout << "Teachers sorted descending per name: " << std::endl;
    university2.printPeople();

    std::cout << std::endl;

    university1.sort(fn, asc);

    std::cout << "Students sorted ascending per FN: " << std::endl;
    university1.printPeople();

    std::cout << std::endl;

    university1.sort(fn, desc);

    std::cout << "Students sorted descending per FN: " << std::endl;
    university1.printPeople();

    std::cout << std::endl;

    university1.sort(averageScore, asc);

    std::cout << "Students sorted ascending per average score: " << std::endl;
    university1.printPeople();

    std::cout << std::endl;

    university1.sort(averageScore, desc);

    std::cout << "Students sorted descending per average score: " << std::endl;
    university1.printPeople();

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