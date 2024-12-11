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

//diff neg and pos

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
    REQUIRE(triangle.toString() == "Triangle 3 4 5");

    Triangle triangle2(5,12,15);
    REQUIRE(triangle2.toString() == "Triangle 5 12 15");

    Triangle triangle3(8,15,17);
    REQUIRE(triangle3.toString() == "Triangle 8 15 17");
    //float
    //negative
}

TEST_CASE("Triangle clone") {
    Triangle triangle(3,4,5);
    std::unique_ptr<Triangle> triangle2 = std::unique_ptr<Triangle>(dynamic_cast<Triangle*>(triangle.clone().release()));
    REQUIRE(triangle2->toString() == "Triangle 3 4 5");
    REQUIRE(triangle2->perimeter() == 12);

    Triangle triangle3(5,12,13);
    std::unique_ptr<Triangle> triangle4 = std::unique_ptr<Triangle>(dynamic_cast<Triangle*>(triangle3.clone().release()));
    REQUIRE(triangle4->toString() == "Triangle 5 12 13");
    REQUIRE(triangle4->perimeter() == 30);
}
//dynamic cast