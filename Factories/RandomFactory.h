#pragma once
#include "Factory.h"

class RandomFactory : public figureFactory {
public:
    Figure* create() override;
    ~RandomFactory() override = default;
};