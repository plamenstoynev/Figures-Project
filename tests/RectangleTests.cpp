#include "catch2/catch_all.hpp"
#include "../src/Rectangle.h"

TEST_CASE("Rectangle constructor") {
    REQUIRE_NOTHROW(Rectangle(3,4));
    REQUIRE_NOTHROW(Rectangle(5,12));
    REQUIRE_NOTHROW(Rectangle(8,15));

    REQUIRE_THROWS(Rectangle(0,4));
    REQUIRE_THROWS(Rectangle(5,0));
    REQUIRE_THROWS(Rectangle(0,0));
}

TEST_CASE("Rectangle perimeter"){
    Rectangle rectangle(3, 4);
    REQUIRE(rectangle.perimeter() == 14);

    Rectangle rectangle2(5, 12);
    REQUIRE(rectangle2.perimeter() == 34);

    Rectangle rectangle3(8, 15);
    REQUIRE(rectangle3.perimeter() == 46);
}

TEST_CASE("Rectangle toString") {
    Rectangle rectangle(3,4);
    REQUIRE(rectangle.toString() == "Rectangle 3 4");

    Rectangle rectangle2(5,12);
    REQUIRE(rectangle2.toString() == "Rectangle 5 12");

    Rectangle rectangle3(8,15);
    REQUIRE(rectangle3.toString() == "Rectangle 8 15");
}

TEST_CASE("Rectangle clone") {
    Rectangle rectangle(3,4);
    std::unique_ptr<Rectangle> rectangle2 = std::unique_ptr<Rectangle>(dynamic_cast<Rectangle*>(rectangle.clone().release()));
    REQUIRE(rectangle2->toString() == "Rectangle 3 4");
    REQUIRE(rectangle2->perimeter() == 14);

    Rectangle rectangle3(5,12);
    std::unique_ptr<Rectangle> rectangle4 = std::unique_ptr<Rectangle>(dynamic_cast<Rectangle*>(rectangle3.clone().release()));
    REQUIRE(rectangle4->toString() == "Rectangle 5 12");
    REQUIRE(rectangle4->perimeter() == 34);
}