#include "Rectangle.h"
#include "catch2/catch_all.hpp"
#include "../stringToFigure/stringToFigure.h"

TEST_CASE("Create figures from string") {
    stringToFigure circle;
    REQUIRE_NOTHROW(circle.createFigureString("Circle 5"));
    REQUIRE(circle.createFigureString("Circle 5")->perimeter() == 31.4159265359); // приблизительно


    stringToFigure rectangle;
    REQUIRE_NOTHROW(rectangle.createFigureString("Rectangle 3 4"));
    REQUIRE(rectangle.createFigureString("Rectangle 3 4")->perimeter() == 14);

    stringToFigure triangle;
    REQUIRE_NOTHROW(triangle.createFigureString("Triangle 3 4 5"));
    REQUIRE(triangle.createFigureString("Triangle 3 4 5")->perimeter() == 12);

    //float tests
}

TEST_CASE("Missing parameters") {
    stringToFigure circle;
    REQUIRE_THROWS(circle.createFigureByString("Circle"));
    REQUIRE_THROWS(circle.createFigureByString("Circle 5 6"));

    //negative

    stringToFigure rectangle;
    REQUIRE_THROWS(rectangle.createFigureByString("Rectangle"));
    REQUIRE_THROWS(rectangle.createFigureByString("Rectangle 3"));
    REQUIRE_THROWS(rectangle.createFigureByString("Recatngle 3 4 5"));

    //negative

    stringToFigure triangle;
    REQUIRE_THROWS(triangle.createFigureByString("Triangle"));
    REQUIRE_THROWS(triangle.createFigureByString("Triangle 3"));
    REQUIRE_THROWS(triangle.createFigureByString("Triangle 3 4"));
    REQUIRE_THROWS(triangle.createFigureByString("Triangle 3 4 5 6"));

    //negative
}

TEST_CASE("Invalid type") {
    stringToFigure exception;
    REQUIRE_THROWS(exception.createFigureByString("unknown 3 4 5"));
}