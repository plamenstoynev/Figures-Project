#include <iostream>
#include <sstream>
#include <string>
#include "Factories//FigureFactory.h"
#include "src/Figure.h"
#include "stringConverter/stringConvertible.h"


int main() {
    std::string command;
    std::string figureData;
    std::string figureType;
    FigureFactory factory;
    Figure** figures = new Figure*[10];
    size_t index = 0;

    std::cout << "Enter command: ";

    while(command != "exit" && index < 3) {
        std::cin >> command;
        if(command == "random") {
            figures[index] = factory.chooseFactory("random")->create();
            index++;
        }
        else if(command == "stream") {
            std::cout << "Enter figure data: ";
            std::cin.ignore();
            std::getline(std::cin, figureData);
            std::istringstream input(figureData);
            figures[index] = factory.chooseFactory("stream", &input)->create();
            index++;
        }
        else if(command == "exit") {
            break;
        }
        else {
            std::cout << "Unknown command" << std::endl;
            continue;
        }
    }

    stringConvertible* stringConverter;

    for (size_t i = 0; i < index; i++) {
        stringConverter = dynamic_cast<stringConvertible*>(figures[i]);
        if (stringConverter != nullptr) {
            std::cout << stringConverter->toString() << std::endl;
        }
    }

    return 0;
}
