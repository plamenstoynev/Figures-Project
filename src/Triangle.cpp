#include "Triangle.h"
#include <stdexcept>


Triangle::Triangle(double a,double b,double c) {
    if (a + b > c && a + c > b && b + c > a) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    else {
        throw std::invalid_argument("Invalid triangle sides");
    }
}

Figure *Triangle::clone() const {
    return new Triangle(*this);
}


double Triangle::perimeter() const  {
    return a + b + c;
}

std::string Triangle::toString() const {
    return "Triangle " + std::to_string(a) + " " + std::to_string(b) + " " + std::to_string(c);
}

