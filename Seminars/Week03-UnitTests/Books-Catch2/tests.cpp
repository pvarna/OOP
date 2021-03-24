#define CATCH_CONFIG_MAIN
#include "..\catch2\catch2.hpp"
#include "book.h"
#include "library.h"
#include "utils.h"

TEST_CASE("Library functions", "[book]")
{
    Library library;
    library.initialize(2);

    SECTION("initialization")
    {
        REQUIRE(library.sizeLibrary == 0);
        REQUIRE(library.capacityLibrary == 2);
        REQUIRE_NOTHROW(library.library);
    }

    library.addBook();
    library.addBook();
    library.addBook();
    SECTION("3 books")
    {
        REQUIRE(library.sizeLibrary == 3);
        REQUIRE(library.capacityLibrary == 4);
        REQUIRE_FALSE(library.sizeLibrary == 3);
    }
}