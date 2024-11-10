#pragma once
#include <istream>
#include "Factory.h"

class StreamFactory : public Factory {
    std::istream& input;
public:
    StreamFactory(std::istream& _input);
    Figure* create() override;
    ~StreamFactory() override = default;
};