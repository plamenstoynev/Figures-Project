#include "RandomFactory.h"
#include <cstdlib>
#include <vector>

#include "../src/Circle.h"
#include "../src/Rectangle.h"
#include "../src/Triangle.h"





std::shared_ptr<Figure>RandomFactory::create() {
    int random = rand() % 3;
    switch (random) {
        case 0 :
            return std::unique_ptr<Figure>(new Circle(rand() % 10));
        case 1 :
            return std::unique_ptr<Figure>(new Rectangle(rand() % 10, rand() % 10));
        case 2 : {
            std::vector<double> sides = Triangle::correctTriangleSides();
            return std::unique_ptr<Figure>(new Triangle(sides[0], sides[1], sides[2]));
        }
    }
}

//again map
//map<number, method>