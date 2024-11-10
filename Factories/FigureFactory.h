#pragma once
#include "AbstractFactory.h"

class FigureFactory : public AbstractFigureFactory {
public:
    Factory* chooseFactory(const std::string& factoryType,std::istream* input = nullptr) override;
    ~FigureFactory() override = default;
};