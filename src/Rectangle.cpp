#include "Rectangle.h"
#include <stdexcept>


Rectangle::Rectangle(double width, double height) {
    if (width > 0 && height > 0) {
        this->width = width;
        this->height = height;
    }
    else
        throw std::invalid_argument("Sides must be greater than 0");
}

Figure *Rectangle::clone() const {
    return new Rectangle(*this);
}


double Rectangle::perimeter() const {
    return 2 * (width + height);
}

std::string Rectangle::toString() const {
    return "Rectangle " + std::to_string(width) + " " + std::to_string(height);
}

