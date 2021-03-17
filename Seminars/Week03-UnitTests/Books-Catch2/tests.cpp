#define CATCH_CONFIG_MAIN
#include "..\catch2\catch2.hpp"
#include "book.h"
#include "library.h"
#include "utils.h"

TEST_CASE("Library functions", "[book]")
{
    Library library;
    SECTION("initialization")
    {
        library.initialize(2);
        REQUIRE(library.sizeLibrary == 0);
        REQUIRE(library.capacityLibrary == 2);
        REQUIRE_NOTHROW(library.library);
    }
}