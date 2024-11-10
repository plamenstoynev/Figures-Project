#include "catch2/catch_all.hpp"
#include "../Factories/RandomFactory.h"

TEST_CASE("RandomFactory create") {
    RandomFactory randomFactory;
    REQUIRE_NOTHROW(randomFactory.create());
}