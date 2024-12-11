#include "Circle.h"
#include <stdexcept>

#include "../stringToFigure/stringToFigure.h"


Circle::Circle(double radius) {
    if (radius <= 0)
        throw std::invalid_argument("Radius must be greater than 0");

    this->radius = radius;
}

std::unique_ptr<Figure>Circle::clone() const {
    return std::make_unique<Circle>(*this);
}

namespace {
    const bool registered = [] {
        stringToFigure::registerFigure("Circle", [](const std::string& figure) -> std::unique_ptr<Figure> {
            std::istringstream iss = std::istringstream(figure);
            double raduis;
            if (!(iss >> raduis))
                throw std::invalid_argument("Invalid number of arguments");

            return std::make_unique<Circle>(Circle(raduis));
        });
        return true;
    }();
}

double Circle::perimeter() const {
    return 2 * 3.14159265359 * radius;
}

std::string Circle::toString() const {
    return "Circle " + formatDouble(radius);
}