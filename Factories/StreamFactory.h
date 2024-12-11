#pragma once
#include <istream>
#include "Factory.h"

class StreamFactory : public Factory {
    std::istream& input;
    //reference and r value reference
    //r value
public:
    StreamFactory(std::istream& _input);

    static std::shared_ptr<std::istream> createStream(std::istream& input);
    static std::shared_ptr<std::istream> createStream(std::istream&& input);
    static std::shared_ptr<std::istream> createStream(const std::string& fileName);

    std::shared_ptr<Figure> create() override;
    ~StreamFactory() override = default;
};