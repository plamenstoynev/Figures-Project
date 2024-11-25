#include "catch2/catch_all.hpp"
#include "../src/Circle.h"

TEST_CASE("Circle constructor") {
    REQUIRE_NOTHROW(Circle(3));
    REQUIRE_NOTHROW(Circle(5));
    REQUIRE_NOTHROW(Circle(8));

    REQUIRE_THROWS(Circle(0));
}

TEST_CASE("Circle perimeter") {
    Circle circle(3);
    REQUIRE(circle.perimeter() == Catch::Approx(18.8495559215));

    Circle circle2(5);
    REQUIRE(circle2.perimeter() == Catch::Approx(31.4159265359));

    Circle circle3(8);
    REQUIRE(circle3.perimeter() == Catch::Approx(50.2654824574));
}

TEST_CASE("Circle toString") {
    Circle circle(3);
    REQUIRE(circle.toString() == "Circle 3");

    Circle circle2(5);
    REQUIRE(circle2.toString() == "Circle 5");

    Circle circle3(8);
    REQUIRE(circle3.toString() == "Circle 8");
}

TEST_CASE("Circle clone") {
    Circle circle(3);
    std::unique_ptr<Circle> circle2 = std::unique_ptr<Circle>(dynamic_cast<Circle*>(circle.clone().release()));
    REQUIRE(circle2->toString() == "Circle 3");
    REQUIRE(circle2->perimeter() == Catch::Approx(18.8495559215));

    Circle circle3(5);
    std::unique_ptr<Circle> circle4 = std::unique_ptr<Circle>(dynamic_cast<Circle*>(circle3.clone().release()));
    REQUIRE(circle4->toString() == "Circle 5");
    REQUIRE(circle4->perimeter() == Catch::Approx(31.4159265359));
}