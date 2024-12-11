#include "catch2/catch_all.hpp"
#include "../Factories/AbstractFactory.h"
#include "../Factories/FigureFactory.h"
#include "../Factories/RandomFactory.h"

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
    REQUIRE_NOTHROW(randomFactory.create()); // seed
}

TEST_CASE("Stream constructor") {
    // Input stream with valid figure definitions
    std::istringstream validInput("Circle 5\nRectangle 3 4\nTriangle 3 4 5");
    StreamFactory validStream(validInput);

    // Test creating figures from a valid input stream
    REQUIRE_NOTHROW(validStream.create()); // Circle
    REQUIRE_NOTHROW(validStream.create()); // Rectangle
    REQUIRE_NOTHROW(validStream.create()); // Triangle

    // Attempting to create more figures when the stream is exhausted should throw
    REQUIRE_THROWS(validStream.create());

    // Input stream with no content
    // std::istringstream emptyInput("");
    // REQUIRE_THROWS_AS(StreamFactory(emptyInput), std::invalid_argument); // Empty stream should throw during construction
    // REQUIRE_THROWS_WITH(StreamFactory(emptyInput), "Invalid input"); // Check the exception message

    // Input stream with invalid content
    std::istringstream invalidInput("Invalid data");
    REQUIRE_NOTHROW(StreamFactory(invalidInput)); // Stream construction should not throw
    REQUIRE_THROWS(validStream.create()); // Parsing invalid content should throw

}