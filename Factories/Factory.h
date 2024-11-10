#pragma once
#include "../src/Figure.h"

class figureFactory {
public:
    virtual Figure* create() = 0;
    virtual ~figureFactory() = default;
};