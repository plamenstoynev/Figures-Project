#include "catch2/catch_all.hpp"
#include "../src/Triangle.h"

TEST_CASE("Triangle constructor") {
    REQUIRE_NOTHROW(Triangle(3,4,5));
    REQUIRE_NOTHROW(Triangle(5,12,13));
    REQUIRE_NOTHROW(Triangle(8,15,17));

    REQUIRE_THROWS(Triangle(1,1,3));
    REQUIRE_THROWS(Triangle(1,3,1));
    REQUIRE_THROWS(Triangle(3,1,1));
}

TEST_CASE("Triangle perimeter"){
    Triangle triangle(3, 4, 5);
    REQUIRE(triangle.perimeter() == 12);

    Triangle triangle2(5, 12, 13);
    REQUIRE(triangle2.perimeter() == 30);

    Triangle triangle3(8, 15, 17);
    REQUIRE(triangle3.perimeter() == 40);
}

TEST_CASE("Triangle toString"){
    Triangle triangle(3,4,5);
    REQUIRE(triangle.toString() == "Triangle 3.000000 4.000000 5.000000");

    Triangle triangle2(5,12,15);
    REQUIRE(triangle2.toString() == "Triangle 5.000000 12.000000 15.000000");

    Triangle triangle3(8,15,17);
    REQUIRE(triangle3.toString() == "Triangle 8.000000 15.000000 17.000000");
}

TEST_CASE("Triangle clone") {
    Triangle triangle(3,4,5);
    Triangle* triangle2 = dynamic_cast<Triangle*>(triangle.clone());
    REQUIRE(triangle2->toString() == "Triangle 3.000000 4.000000 5.000000");
    REQUIRE(triangle2->perimeter() == 12);
    delete triangle2;

    Triangle triangle3(5,12,13);
    Triangle* triangle4 = dynamic_cast<Triangle*>(triangle3.clone());
    REQUIRE(triangle4->toString() == "Triangle 5.000000 12.000000 13.000000");
    REQUIRE(triangle4->perimeter() == 30);
    delete triangle4;
}

