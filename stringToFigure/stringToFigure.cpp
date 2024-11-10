#include "stringToFigure.h"
#include <sstream>
#include <stdexcept>

#include "../src/Triangle.h"
#include "../src/Rectangle.h"
#include "../src/Circle.h"

Figure* stringToFigure::createFigureByString(const std::string &figure) {
    char type;
    type = figure[0];

    switch (type) {
        case 'T': {
            std::istringstream iss = std::istringstream(figure.substr(8));

            if (iss.str().size() < 5 || iss.str().size() > 7)
                throw std::invalid_argument("Invalid number of arguments");

            double a, b, c;
            iss >> a >> b >> c;
            return new Triangle(a, b, c);
        }
        case 'R': {
            std::istringstream iss = std::istringstream(figure.substr(10));

            if (iss.str().size() < 3 || iss.str().size() >= 5)
                throw std::invalid_argument("Invalid number of arguments");

            double width, height;
            iss >> width >> height;
            return new Rectangle(width, height);
        }
    case 'C': {
            std::istringstream iss = std::istringstream(figure.substr(7));

            if (iss.str().size() > 1 || iss.str().size() == 0)
                throw std::invalid_argument("Invalid number of arguments");

            double radius;
            iss >> radius;
            return new Circle(radius);
        }
        default:
            throw std::invalid_argument("Invalid figure type");
    }
}

