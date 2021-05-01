#include <iostream>
#include <cstring>
#include "utils.h"

int main ()
{
    std::cout << "Open file:" << std::endl;
    std::cout << ">";

    char fileName[BUFFER_LINE_SIZE];
    std::cin.getline(fileName, BUFFER_LINE_SIZE);

    int studentsCount = getCountOfLines(fileName) - 1;

    std::cout << "Count of students: " << studentsCount << std::endl;

    if (studentsCount <= 0)
    {
        std::cout << "Error while reading data from the file" << std::endl;
        return 1;   
    }

    Student* studentsCollection = new Student[studentsCount];

    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cout << "Error!" << std::endl;

		delete[] studentsCollection;

		return -1;
    }

    //std::cout << "Stigash li tuka" << std::endl;

    int line = 1;
	while (!file.eof())
	{
		char temp[BUFFER_LINE_SIZE];
		file.getline(temp, BUFFER_LINE_SIZE);

		if (line == 1)
		{
			++line;
			continue;
		}

        //std::cout << "Stigash li tuka" << line << std::endl;

		readStudent(temp, studentsCollection[line - 2]);
		++line;
	}
    file.close();

    std::cout << "File successfully opened!" << std::endl;

    /*for (std::size_t i = 0; i < studentsCount; ++i)
    {
        std::cout << studentsCollection[i].firstName << " " << studentsCollection[i].family << " " << studentsCollection[i].email << " " << studentsCollection[i].facultyNumber << std::endl;
    }*/

    char commandLine[BUFFER_LINE_SIZE];
    do
    {
        std::cout << ">";
        std::cin.getline(commandLine, BUFFER_LINE_SIZE);
        std::size_t commandLineLength = strlen(commandLine);

        //first argument (edit, save ...)
        std::size_t firstArgumentLength = indexOfFirstSpaceOrTerminatingZero(commandLine);
        char* commandFirstArgument = new char[firstArgumentLength + 1];

        for (std::size_t i = 0; i < firstArgumentLength; ++i)
        {
            commandFirstArgument[i] = commandLine[i];
        }
        commandFirstArgument[firstArgumentLength] = '\0';

        if (commandLineLength == firstArgumentLength)
        {
            continue;
        }

        //second argument (students.csv, 45543 ...)
        std::size_t secondArgumentLength = commandLineLength - firstArgumentLength - 1;
        char* commandSecondArgument = new char[secondArgumentLength + 1];

        for (std::size_t i = 0; i < secondArgumentLength; ++i)
        {
            commandSecondArgument[i] = commandLine[firstArgumentLength + 1 + i];
        }
        commandSecondArgument[secondArgumentLength] = '\0';

        if (strcmp(commandFirstArgument, "print") == 0)
        {
            int facultyNumber = atoi(commandSecondArgument);

            //std::cout << "Stigash li tuka?? Ako da, kolko e fn-to " << facultyNumber << std::endl;

            bool result = printStudent(studentsCollection, studentsCount, facultyNumber);

            if (!result)
            {
                std::cout << "Student with faculty number: " << facultyNumber << " doesn't exist!" << std::endl;
            }
        }
        else if (strcmp(commandFirstArgument, "edit") == 0)
        {
            int facultyNumber = atoi(commandSecondArgument);

            //we have a third argument here. It's in the second arguments string

            std::size_t separator = indexOfFirstSpaceOrTerminatingZero(commandSecondArgument);

            std::size_t thirdArgumentLength = secondArgumentLength - separator;
            char* commandThirdArgument = new char[thirdArgumentLength + 1];

            for (std::size_t i = 0; i < thirdArgumentLength; ++i)
            {
                commandThirdArgument[i] = commandSecondArgument[separator + 1 + i];
            }
            commandThirdArgument[thirdArgumentLength] = '\0';

            bool result = editFirstName(studentsCollection, studentsCount, facultyNumber, commandThirdArgument);

            if (result)
            {
                std::cout << "Successfully changed name!" << std::endl;
            }
            else
            {
                std::cout << "Student with faculty number: " << facultyNumber << " doesn't exist!" << std::endl;
            }

            delete[] commandThirdArgument;
        }
        else if (strcmp(commandFirstArgument, "save") == 0)
        {
            bool result = saveStudentsToFile(studentsCollection, studentsCount, commandSecondArgument);

            if (result)
            {
                std::cout << "Successfully saved to file: " << commandSecondArgument << std::endl;
            }
            else
            {
                std::cout << "Error while saving in file: " << commandSecondArgument << std::endl;
            }
        }

        delete[] commandFirstArgument;
        delete[] commandSecondArgument;

    } while (strcmp(commandLine, "quit"));
    
    delete[] studentsCollection;

    return 0;
}