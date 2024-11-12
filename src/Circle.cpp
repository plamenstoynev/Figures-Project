#include "Circle.h"
#include <stdexcept>


Circle::Circle(double radius) {
    if (radius <= 0)
        throw std::invalid_argument("Radius must be greater than 0");

    this->radius = radius;
}

std::unique_ptr<Figure>Circle::clone() const {
    return std::make_unique<Circle>(*this);
}


double Circle::perimeter() const {
    return 2 * 3.14159265359 * radius;
}

std::string Circle::toString() const {
    return "Circle " + formatDouble(radius);
}