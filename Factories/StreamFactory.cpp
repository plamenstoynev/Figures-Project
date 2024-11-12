#include "StreamFactory.h"
#include "../stringToFigure/stringToFigure.h"

StreamFactory::StreamFactory(std::istream& _input) : input(_input) {
    if(!input.good() || input.peek() == EOF)
        throw std::runtime_error("Invalid input");
}

std::unique_ptr<Figure> StreamFactory::create() {
    std::string figure;
    if(std::getline(input, figure))
        return std::unique_ptr<Figure>(stringToFigure().createFigureByString(figure));
    else
        throw std::invalid_argument("Invalid input");
}