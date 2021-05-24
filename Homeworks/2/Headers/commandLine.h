#pragma once

#include <vector>
#include <string>
#include <cstddef>

const std::size_t NUMBER_OF_COMMANDS_WITH_ONE_ARGUMENT = 2;
const std::size_t NUMBER_OF_COMMANDS_WITH_TWO_ARGUMENTS = 3;
const std::size_t NUMBER_OF_COMMANDS_WITH_THREE_ARGUMENTS = 4;

const std::size_t MIN_NUMBER_OF_ARGUMENTS = 1;
const std::size_t MAX_NUMBER_OF_ARGUMENTS = 3;

class CommandLine
{
private:
    static std::string validCommandsOneArgument[NUMBER_OF_COMMANDS_WITH_ONE_ARGUMENT];
    static std::string validCommandsTwoArguments[NUMBER_OF_COMMANDS_WITH_TWO_ARGUMENTS];
    static std::string validCommandsThreeArguments[NUMBER_OF_COMMANDS_WITH_THREE_ARGUMENTS];
    std::string mainCommand = "";
    std::string secondArgument = "";
    std::string thirdArgument = "";

    std::size_t getNumberOfQuotes(std::string string);
    std::string stringToUpper(std::string& string);
    void removeExtraWhitespaces(std::string& string);
    void removeEmptyArguments(std::vector<std::string>& arguments);
    std::vector<std::string> parseCommandLine(std::string commandLine);
    bool isMainCommandValid(std::string command);
    bool isNumberOfArgumentsCorrect(std::vector<std::string> arguments);

public:
    CommandLine(std::string commandLine);

    std::string getMainCommand() const;
    std::string getSecondArgument() const;
    std::string getThirdArgument() const;
};