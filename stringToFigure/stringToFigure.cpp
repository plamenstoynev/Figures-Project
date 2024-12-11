#include "stringToFigure.h"
#include <sstream>
#include <stdexcept>

#include "../src/Triangle.h"
#include "../src/Rectangle.h"
#include "../src/Circle.h"

#include "stringToFigure.h"

#include "stringToFigure.h"
#include <sstream>
#include <stdexcept>

#include "../src/Triangle.h"
#include "../src/Rectangle.h"
#include "../src/Circle.h"

std::map<std::string, stringToFigure::CreateFigureMethod>& stringToFigure::getRegistry() {
    static std::map<std::string, CreateFigureMethod> registry;
    return registry;
}

void stringToFigure::registerFigure(const std::string& name, CreateFigureMethod createMethod) {
    getRegistry()[name] = createMethod;
}

std::unique_ptr<Figure> stringToFigure::createFigureString(const std::string& data) {
    std::string param = data.substr(data.find(' ') + 1, data.size());
    std::string figure = data.substr(0, data.find(' '));

    auto it = getRegistry().find(figure);
    if (it != getRegistry().end()) {
        return it->second(param);
    }
    throw std::invalid_argument("Unknown figure type: " + figure);
}