#pragma once
#include "../src/Figure.h"

class Factory {
public:
    virtual Figure* create() = 0;
    virtual ~Factory() = default;
};