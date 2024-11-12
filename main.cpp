#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Factories//FigureFactory.h"
#include "src/Figure.h"
#include "stringConverter/stringConvertible.h"


int main() {
    std::string command;
    FigureFactory factory;
    std::vector<Figure*> figures;
    stringConvertible* stringConverter;
    size_t index = 0;
    std::ofstream file("figures.txt");

    while(command != "exit" && index < 3) {
        std::cout << "Enter command: (random or stream)";
        std::cin >> command;
        if(command == "random") {
            figures.push_back(factory.chooseFactory("random")->create());
            index++;
        }
        else if(command == "stream") {
            std::cout << "Enter figure data: ";
            std::cin.ignore();
            std::getline(std::cin, command);
            std::istringstream input(command);
            figures.push_back(factory.chooseFactory("stream", &input)->create());
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

    for (size_t i = 0; i < index; i++) {
        stringConverter = dynamic_cast<stringConvertible*>(figures[i]);
        if (stringConverter != nullptr) {
            std::cout << stringConverter->toString() << std::endl;

            file << stringConverter->toString();
            file << std::endl;
        }
    }
    return 0;
}
