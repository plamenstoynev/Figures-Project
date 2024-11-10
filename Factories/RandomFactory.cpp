#include "RandomFactory.h"
#include <cstdlib>

#include "../src/Circle.h"
#include "../src/Rectangle.h"
#include "../src/Triangle.h"

Figure *RandomFactory::create() {
    int random = rand() % 3;
    switch (random) {
        case 0 :
            return new Circle(rand()% 10);
        case 1 :
            return new Rectangle(rand() % 10, rand() % 10);
        case 2 :
            return new Triangle(rand() % 10, rand() % 10, rand() % 10);
    }
}
