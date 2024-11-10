#include "Rectangle.h"
#include "catch2/catch_all.hpp"
#include "../Factories/AbstractFactory.h"
#include "../Factories/FigureFactory.h"

TEST_CASE("Abstract Factory tests") {
    FigureFactory factory;
    std::istringstream input("Rectangle 3 4");
    REQUIRE_NOTHROW(factory.chooseFactory("random"));
    REQUIRE_NOTHROW(factory.chooseFactory("stream", &input));

    REQUIRE_THROWS(factory.chooseFactory("stream", nullptr));
    REQUIRE_THROWS(factory.chooseFactory("unknown"));
}