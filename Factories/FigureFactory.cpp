#include "FigureFactory.h"

Factory *FigureFactory::chooseFactory(const std::string &factoryType, std::istream *input)  {
    if (factoryType == "random") {
        return new RandomFactory();
    } else if (factoryType == "stream") {
        if (input == nullptr) {
            throw std::invalid_argument("Input stream is null");
        }
        return new StreamFactory(*input);
    } else {
        throw std::invalid_argument("Unknown factory type");
    }
}
