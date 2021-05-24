//#define CATCH_CONFIG_MAIN
#include "../catch2/catch2.hpp"
#include "../Headers/commandLine.h"

TEST_CASE("check valid commands and getters")
{   
    SECTION("VEHICLE")
    {
        CommandLine cmd1("VEHICLE V3945PK \"Pesho's car\""); 
        REQUIRE_NOTHROW(CommandLine("VEHICLE V3945PK \"Pesho's car\""));
        REQUIRE(cmd1.getMainCommand() == "VEHICLE");
        REQUIRE(cmd1.getSecondArgument() == "V3945PK");
        REQUIRE(cmd1.getThirdArgument() == "Pesho's car");

        CommandLine cmd2("vehicle V3945PK \"Pesho's car\""); 
        REQUIRE_NOTHROW(CommandLine("vehicle V3945PK \"Pesho's car\""));
        REQUIRE(cmd2.getMainCommand() == "VEHICLE");
        REQUIRE(cmd2.getSecondArgument() == "V3945PK");
        REQUIRE(cmd2.getThirdArgument() == "Pesho's car");

        CommandLine cmd3("VeHiclE V3945PK \"Pesho's car\""); 
        REQUIRE_NOTHROW(CommandLine("vehicle V3945PK \"Pesho's car\""));
        REQUIRE(cmd3.getMainCommand() == "VEHICLE");
        REQUIRE(cmd3.getSecondArgument() == "V3945PK");
        REQUIRE(cmd3.getThirdArgument() == "Pesho's car");
    }

    SECTION("PERSON")
    {
        CommandLine cmd("person \"Pesho Kolev\" 3945");
        REQUIRE_NOTHROW(CommandLine("person \"Pesho Kolev\" 3945"));
        REQUIRE(cmd.getMainCommand() == "PERSON");
        REQUIRE(cmd.getSecondArgument() == "Pesho Kolev");
        REQUIRE(cmd.getThirdArgument() == "3945");
    }

    SECTION("ACQUIRE")
    {
        CommandLine cmd("ACQUIRE 3945 V3945PK");
        REQUIRE_NOTHROW(CommandLine("ACQUIRE 3945 V3945PK")); 
        REQUIRE(cmd.getMainCommand() == "ACQUIRE");
        REQUIRE(cmd.getSecondArgument() == "3945");
        REQUIRE(cmd.getThirdArgument() == "V3945PK");   
    }

    SECTION("RELEASE")
    {
        CommandLine cmd("releASE 3945 V3945PK");
        REQUIRE_NOTHROW(CommandLine("releASE 3945 V3945PK"));
        REQUIRE(cmd.getMainCommand() == "RELEASE");
        REQUIRE(cmd.getSecondArgument() == "3945");
        REQUIRE(cmd.getThirdArgument() == "V3945PK"); 
    }

    SECTION("REMOVE")
    {
        CommandLine cmd1("REMOVE 3945");
        REQUIRE_NOTHROW(CommandLine("REMOVE 3945"));
        REQUIRE(cmd1.getMainCommand() == "REMOVE");
        REQUIRE(cmd1.getSecondArgument() == "3945");
        REQUIRE(cmd1.getThirdArgument() == "");

        CommandLine cmd2("remOve V3945PK");
        REQUIRE_NOTHROW(CommandLine("REMOVE V3945PK"));
        REQUIRE(cmd2.getMainCommand() == "REMOVE");
        REQUIRE(cmd2.getSecondArgument() == "V3945PK");
        REQUIRE(cmd2.getThirdArgument() == "");
    }

    SECTION("SAVE")
    {
        CommandLine cmd("SAVE ../Files/proba.txt");
        REQUIRE_NOTHROW(CommandLine("SAVE ../Files/proba.txt"));
        REQUIRE(cmd.getMainCommand() == "SAVE");
        REQUIRE(cmd.getSecondArgument() == "../Files/proba.txt");
        REQUIRE(cmd.getThirdArgument() == "");
    }

    SECTION("SHOW")
    {
        CommandLine cmd1("SHOW PEOPLE");
        REQUIRE_NOTHROW(CommandLine("SHOW PEOPLE"));
        REQUIRE(cmd1.getMainCommand() == "SHOW");
        REQUIRE(cmd1.getSecondArgument() == "PEOPLE");
        REQUIRE(cmd1.getThirdArgument() == "");

        CommandLine cmd2("SHOW VEHICLES");
        REQUIRE_NOTHROW(CommandLine("SHOW VEHICLES"));
        REQUIRE(cmd2.getMainCommand() == "SHOW");
        REQUIRE(cmd2.getSecondArgument() == "VEHICLES");
        REQUIRE(cmd2.getThirdArgument() == "");

        CommandLine cmd3("SHOW 3945");
        REQUIRE_NOTHROW(CommandLine("SHOW 3945"));
        REQUIRE(cmd3.getMainCommand() == "SHOW");
        REQUIRE(cmd3.getSecondArgument() == "3945");
        REQUIRE(cmd3.getThirdArgument() == "");

        CommandLine cmd4("SHOW V3945PK");
        REQUIRE_NOTHROW(CommandLine("SHOW V3945PK"));
        REQUIRE(cmd4.getMainCommand() == "SHOW");
        REQUIRE(cmd4.getSecondArgument() == "V3945PK");
        REQUIRE(cmd4.getThirdArgument() == "");
    }

    SECTION("HELP")
    {
        CommandLine cmd("HELP");
        REQUIRE_NOTHROW(CommandLine("HELP"));
        REQUIRE(cmd.getMainCommand() == "HELP");
        REQUIRE(cmd.getSecondArgument() == "");
        REQUIRE(cmd.getThirdArgument() == "");
    }

    SECTION("EXIT")
    {
        CommandLine cmd("EXIT");
        REQUIRE_NOTHROW(CommandLine("EXIT"));
        REQUIRE(cmd.getMainCommand() == "EXIT");
        REQUIRE(cmd.getSecondArgument() == "");
        REQUIRE(cmd.getThirdArgument() == "");
    }
}

TEST_CASE("check valid commands with extra whitespaces")
{
    CommandLine cmd1("     SHOW      V3945PK       ");
    REQUIRE_NOTHROW(CommandLine("     SHOW      V3945PK       "));
    REQUIRE(cmd1.getMainCommand() == "SHOW");
    REQUIRE(cmd1.getSecondArgument() == "V3945PK");
    REQUIRE(cmd1.getThirdArgument() == "");

    CommandLine cmd2("person      \"   Pesho      Kolev     \"       3945");
    REQUIRE_NOTHROW(CommandLine("person      \"   Pesho      Kolev     \"       3945"));
    REQUIRE(cmd2.getMainCommand() == "PERSON");
    REQUIRE(cmd2.getSecondArgument() == "Pesho Kolev");
    REQUIRE(cmd2.getThirdArgument() == "3945");
}

TEST_CASE("check invalid main command")
{
    REQUIRE_THROWS(CommandLine("perrson Peter 3945"));
    REQUIRE_THROWS(CommandLine("SEVE test.txt"));
    REQUIRE_THROWS(CommandLine("SHOWW PERSON"));
    REQUIRE_THROWS(CommandLine("exxit"));
}

TEST_CASE("check invalid number of arguments")
{
    REQUIRE_THROWS(CommandLine("PERSON Peter"));
    REQUIRE_THROWS(CommandLine("VEHICLE V3945PK"));
    REQUIRE_THROWS(CommandLine("ACQUIRE 3945"));
    REQUIRE_THROWS(CommandLine("RELEASE V3945PK"));
    REQUIRE_THROWS(CommandLine("REMOVE 3945 V3945PK"));
    REQUIRE_THROWS(CommandLine("SAVE 3945 test.txt"));
    REQUIRE_THROWS(CommandLine("SHOW PERSON VEHICLE"));
    REQUIRE_THROWS(CommandLine("HELP me"));
    REQUIRE_THROWS(CommandLine("EXIT now"));
}

TEST_CASE("empty command")
{
    REQUIRE_THROWS(CommandLine(""));
}