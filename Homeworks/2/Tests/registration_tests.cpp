#define CATCH_CONFIG_MAIN
#include "../catch2/catch2.hpp"
#include "../Headers/registration.h"

TEST_CASE("Test validation + constructor")
{
    SECTION("Valid registration numbers")
    {
        REQUIRE_NOTHROW(Registration("V3945PK"));
        REQUIRE_NOTHROW(Registration("SA3945PK"));
    }

    SECTION("Invalid registration numbers with wrong length")
    {
        REQUIRE_THROWS(Registration("S2532P"));
        REQUIRE_THROWS(Registration(""));
        REQUIRE_THROWS(Registration("VS2626KLP"));
        REQUIRE_THROWS(Registration("ABCDEF"));
        REQUIRE_THROWS(Registration("C11D"));
    }

    SECTION("Invalid registration numbers with length 8")
    {
        REQUIRE_THROWS(Registration("88888888"));
        REQUIRE_THROWS(Registration("VV88888V"));
        REQUIRE_THROWS(Registration("VV8V88VV"));
        REQUIRE_THROWS(Registration("V88888VV"));
        REQUIRE_THROWS(Registration("VVVVVVVV"));
        REQUIRE_THROWS(Registration("ABC34DEF"));
    }

    SECTION("Invalid registration numbers with length 7")
    {
        REQUIRE_THROWS(Registration("8888888"));
        REQUIRE_THROWS(Registration("VV8888V"));
        REQUIRE_THROWS(Registration("V8V88VV"));
        REQUIRE_THROWS(Registration("V88888V"));
        REQUIRE_THROWS(Registration("VVVVVVV"));
        REQUIRE_THROWS(Registration("ABC34DE"));
    }
}