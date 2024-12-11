#pragma once
#include <memory>
#include "Factory.h"

class RandomFactory : public Factory {
public:
    std::shared_ptr<Figure> create() override;
    ~RandomFactory() override = default;
};