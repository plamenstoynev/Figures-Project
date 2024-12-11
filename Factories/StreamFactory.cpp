#include "StreamFactory.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "../stringToFigure/stringToFigure.h"

StreamFactory::StreamFactory(std::istream& _input) : input(_input) {
    if (!input) {
        std::cerr << "StreamFactory constructor: Invalid input stream" << std::endl;
        throw std::invalid_argument("Invalid input");
    }
}

std::shared_ptr<Figure> StreamFactory::create() {
    std::string figure;
    if (std::getline(input, figure))
        return std::unique_ptr<Figure>(stringToFigure().createFigureString(figure));
    else
        throw std::invalid_argument("Invalid input");
}

std::shared_ptr<std::istream> StreamFactory::createStream(std::istream& input){
    auto ptr = std::make_shared<std::stringstream>();
    *ptr << input.rdbuf();
    return ptr;
}

std::shared_ptr<std::istream> StreamFactory::createStream(std::istream &&input) {
    auto ptr = std::make_shared<std::stringstream>();
    *ptr << input.rdbuf();
    return ptr;
}

std::shared_ptr<std::istream> StreamFactory::createStream(const std::string &fileName) {
    auto file = std::make_shared<std::ifstream>(fileName);

    if(!file->is_open())
        throw std::runtime_error("Invalid file");

    return file;
}