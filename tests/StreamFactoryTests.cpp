#include "catch2/catch_all.hpp"
#include "../Factories/StreamFactory.h"

TEST_CASE("Stream constructor") {
    std::istringstream input("Circle 5\nRectangle 3 4\nTriangle 3 4 5");
    StreamFactory stream(input);
    REQUIRE_NOTHROW(stream.create());
    REQUIRE_NOTHROW(stream.create());
    REQUIRE_NOTHROW(stream.create());

    std::stringstream emptyInput;
    REQUIRE_THROWS(StreamFactory(emptyInput));
}