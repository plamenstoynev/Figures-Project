#pragma once
#include "../src/Figure.h"
#include <memory>

class Factory {
public:
    virtual std::shared_ptr<Figure> create() = 0;
    virtual ~Factory() = default;
};