#pragma once
#include "Factory.h"

class RandomFactory : public Factory {
public:
    Figure* create() override;
    ~RandomFactory() override = default;
};