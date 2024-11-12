#pragma once
#include "Factory.h"
#include "StreamFactory.h"


class AbstractFigureFactory {
public:
    virtual std::unique_ptr<Factory> chooseFactory(const std::string& factoryType,std::istream* input = nullptr) = 0;
    virtual ~AbstractFigureFactory() = default;
};