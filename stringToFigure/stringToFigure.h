#pragma once
#include <string>
#include "../src/Figure.h"

class stringToFigure {
public:
    Figure* createFigureByString(const std::string& figure);
};
