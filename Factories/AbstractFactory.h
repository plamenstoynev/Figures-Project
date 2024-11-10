#pragma once
#include "../src/Figure.h"
#include "Factory.h"
#include "RandomFactory.h"
#include "StreamFactory.h"
#include <string>
#include <stdexcept>

class AbstractFigureFactory {
public:
    virtual Factory* chooseFactory(const std::string& factoryType,std::istream* input = nullptr) = 0;
    virtual ~AbstractFigureFactory() = default;
};