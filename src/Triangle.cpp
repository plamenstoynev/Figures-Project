#include "Triangle.h"
#include <stdexcept>


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

std::unique_ptr<Figure>Triangle::clone() const {
    return std::make_unique<Triangle>(*this);
}


double Triangle::perimeter() const  {
    return a + b + c;
}

std::string Triangle::toString() const {
    return "Triangle " + formatDouble(a) + " " + formatDouble(b) + " " + formatDouble(c);
}

