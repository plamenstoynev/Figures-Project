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

TEST_CASE("RandomFactory create") {
    RandomFactory randomFactory;
    REQUIRE_NOTHROW(randomFactory.create());
}

TEST_CASE("Stream constructor") {
    std::istringstream input("Circle 5\nRectangle 3 4\nTriangle 3 4 5");
    StreamFactory stream(input);
    REQUIRE_NOTHROW(stream.create());
    REQUIRE_NOTHROW(stream.create());
    REQUIRE_NOTHROW(stream.create());

    std::stringstream emptyInput;
    REQUIRE_THROWS(StreamFactory(emptyInput));
}