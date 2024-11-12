#include "RandomFactory.h"
#include <cstdlib>
#include <vector>

#include "../src/Circle.h"
#include "../src/Rectangle.h"
#include "../src/Triangle.h"

std::vector<double> correctTriangleSides() {
    std::vector<double> result(3);

    do {
        result[0] = rand() % 10;
        result[1] = rand() % 10;
        result[2] = rand() % 10;
    }
    while (result[0] + result[1] <= result[2] || result[0] + result[2] <= result[1] || result[1] + result[2] <= result[0]);

    return result;
}

std::unique_ptr<Figure>RandomFactory::create() {
    int random = rand() % 3;
    switch (random) {
        case 0 :
            return std::unique_ptr<Figure>(new Circle(rand() % 10));
        case 1 :
            return std::unique_ptr<Figure>(new Rectangle(rand() % 10, rand() % 10));
        case 2 : {
            std::vector<double> sides = correctTriangleSides();
            return std::unique_ptr<Figure>(new Triangle(sides[0], sides[1], sides[2]));
        }
    }
}