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
    std::vector<std::shared_ptr<Figure>> figures;
    stringConvertible* stringConverter;
    std::ofstream file("figures.txt");

    std::cout << "Rules for entering data and commands \n"
                    "random - to create a random figure\n"
                    "stream - to create a figure from the stream\n"
                    "exit - to exit the program\n"
                    "For example, to create a triangle, enter 'stream Triangle 3 4 5'\n"
                    "For example, to create a rectangle, enter 'stream Rectangle 3 4'\n"
                    "For example, to create a circle, enter 'stream Circle 3"<<
                    std::endl;


    while(command != "exit") {
        std::cout << "Enter command: ";
        std::cin >> command;

        if(command == "random") {
            try {
                figures.push_back(factory.chooseFactory("random")->create());
            } catch (std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
        }

        else if(command == "stream") {
            std::cout << "Enter figure data: ";
            std::cin.ignore();
            try {
                figures.push_back(factory.chooseFactory("stream", &std::cin)->create());
            } catch (std::invalid_argument& e) {
                std::cout << e.what() << std::endl;
            }
        }

        else if(command == "exit") {
            break;
        }

        else {
            std::cout << "Unknown command" << std::endl;
            continue;
        }
    }

    std::cout << "Perimeters of figures: " << std::endl;

    for (const auto & figure : figures) {
        std::unique_ptr<Figure> clone = figure->clone();
        std::cout << "Perimeter: " << clone->perimeter() << std::endl;
    }

    std::cout << "Figures: " << std::endl;

    for (const auto & figure : figures) {
        stringConverter = dynamic_cast<stringConvertible*>(figure.get());
        if (stringConverter != nullptr) {
            std::cout << stringConverter->toString() << std::endl;

            file << stringConverter->toString();
            file << std::endl;
        }
    }
    return 0;
}
