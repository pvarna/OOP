#ifndef FUNCTIONS_H
#define FUNCTION_H

/**
 * \struct Grade
 * \brief Strucure for the grades of the students
 * \author P. Kolev
*/
struct Grade
{
    char* subject; //!< stores the name of the subject
    double grade; //!< stores the grade for the entered grade

    //! Function to read a grade from the console
    void readGrade();
};

/**
 * \struct Student
 * \brief Strucure for details about a student
 * \author P. Kolev
*/
struct Student
{
    char* name; //!< stores the name of the student
    char EGN[10]; //!< stores the EGN of the student
    char facultyNumber[5]; //!< stores the faculty number of the student
    Grade grades[5]; //!< stores 5 grades of the student

    //! Function to read informarmation about the student from the console
    void readStudent();

    //! Function to capitalise all first letters of the 3 names of the student
    void fixName();

    //! Function to calculate the average grade of the student
    double averageScore();

    //! Function to get only the first and the last name of the student
    char* firstLastName();
};

/**
 * \struct Students
 * \brief Strucure for a list of students
 * \author P. Kolev
*/
struct Students
{
    Student students[100]; //!< stores information about each student
    int numberOfStudents = 0; //!< stores the bumber of students in the array

    //! Function to add a new student to the array
    void addStudent();

    //! Function to print the names and the average score of the students born in March
    void printStudentsBornInMarch();

    //! Function to print the name and the average score of the student with highest average score
    void printStudentWithHighestScore();

    //! Function to deallocate the allocated memory for the array of students
    void deallocateMemory();
};

//! Function to capitalise a letter if needed
char toUpper(char ch);

//! Function to print the main menu of the program
void printMenu();

#endif