#include "FigureFactory.h"
#include "RandomFactory.h"

std::shared_ptr<Factory> FigureFactory::chooseFactory(const std::string &factoryType, std::istream *input)  {
    if (factoryType == "random") {
        return std::shared_ptr<Factory>(new RandomFactory());
    } else if (factoryType == "stream") {
        if (input == nullptr) {
            throw std::invalid_argument("Input stream is null");
        }
        return std::shared_ptr<Factory>(new StreamFactory(*input));
    } else {
        throw std::invalid_argument("Unknown factory type");
    }
}
//random shared, stream unique
//think about it