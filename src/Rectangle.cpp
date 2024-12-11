#include "Rectangle.h"
#include <stdexcept>

#include "../stringToFigure/stringToFigure.h"


Rectangle::Rectangle(double width, double height) {
    if (width > 0 && height > 0) {
        this->width = width;
        this->height = height;
    }
    else
        throw std::invalid_argument("Sides must be greater than 0");
}

namespace {
    const bool registered = [] {
        stringToFigure::registerFigure("Rectangle", [](const std::string& figure) -> std::unique_ptr<Figure> {
            std::istringstream iss(figure);
            double width, height;
            if (!(iss >> width >> height))
                throw std::invalid_argument("Invalid number of arguments");

            return std::make_unique<Rectangle>(Rectangle(width, height));
        });
        return true;
    }();
}

std::unique_ptr<Figure>Rectangle::clone() const {
    return std::make_unique<Rectangle>(*this);
}


double Rectangle::perimeter() const {
    return 2 * (width + height);
}

std::string Rectangle::toString() const {
    return "Rectangle " + formatDouble(width) + " " + formatDouble(height);
}

