#pragma once
#include <string>
#include <map>
#include "../src/Figure.h"

#pragma once
#include <string>
#include "../src/Figure.h"

class stringToFigure {
public:
    using CreateFigureMethod = std::function<std::unique_ptr<Figure>(const std::string&)>;

    static void registerFigure(const std::string& figure, CreateFigureMethod method);

    std::unique_ptr<Figure> createFigureString(const std::string &data);
private:
    static std::map<std::string, CreateFigureMethod>& getRegistry();
};