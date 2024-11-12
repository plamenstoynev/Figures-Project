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
    REQUIRE(rectangle.toString() == "Rectangle 3.000000 4.000000");

    Rectangle rectangle2(5,12);
    REQUIRE(rectangle2.toString() == "Rectangle 5.000000 12.000000");

    Rectangle rectangle3(8,15);
    REQUIRE(rectangle3.toString() == "Rectangle 8.000000 15.000000");
}

TEST_CASE("Rectangle clone") {
    Rectangle rectangle(3,4);
    Rectangle* rectangle2 = dynamic_cast<Rectangle*>(rectangle.clone().get());
    REQUIRE(rectangle2->toString() == "Rectangle 3.000000 4.000000");
    REQUIRE(rectangle2->perimeter() == 14);

    Rectangle rectangle3(5,12);
    Rectangle* rectangle4 = dynamic_cast<Rectangle*>(rectangle3.clone().get());
    REQUIRE(rectangle4->toString() == "Rectangle 5.000000 12.000000");
    REQUIRE(rectangle4->perimeter() == 34);
}