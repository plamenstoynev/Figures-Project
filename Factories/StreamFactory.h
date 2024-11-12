#pragma once
#include <istream>
#include "Factory.h"

class StreamFactory : public Factory {
    std::istream& input;
public:
    StreamFactory(std::istream& _input);
    std::unique_ptr<Figure> create() override;
    ~StreamFactory() override = default;
};