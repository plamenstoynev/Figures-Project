#include "Triangle.h"
#include <stdexcept>

#include "../stringToFigure/stringToFigure.h"


Triangle::Triangle(double a,double b,double c) {
    if (a + b > c && a + c > b && b + c > a && a > 0 && b > 0 && c > 0) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    else {
        throw std::invalid_argument("Invalid triangle sides");
    }
}

namespace {
    const bool registered = [] {
        stringToFigure::registerFigure("Triangle", [](const std::string& figure) -> std::unique_ptr<Figure> {
            std::istringstream iss(figure);
            double a, b, c;
            if (!(iss >> a >> b >> c))
                throw std::invalid_argument("Invalid number of arguments");

            return std::make_unique<Triangle>(Triangle(a, b, c));
        });
        return true;
    }();
}


std::unique_ptr<Figure>Triangle::clone() const {
    return std::make_unique<Triangle>(*this);
}


double Triangle::perimeter() const  {
    return a + b + c;
}

std::string Triangle::toString() const {
    return "Triangle " + formatDouble(a) + " " + formatDouble(b) + " " + formatDouble(c);
}

std::vector<double> Triangle::correctTriangleSides() {
    std::vector<double> result(3);

    do {
        result[0] = rand() % 10;
        result[1] = rand() % 10;
        result[2] = rand() % 10;
    }
    while (result[0] + result[1] <= result[2] || result[0] + result[2] <= result[1] || result[1] + result[2] <= result[0]);

    //less loop more math
    //first second then third

    return result;
}
