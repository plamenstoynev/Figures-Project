#pragma once
#include "Figure.h"
#include "../stringConverter/stringConvertible.h"
#include <string>

class Rectangle : public Figure, public stringConvertible {
private:
    double width = 0;
    double height = 0;

public:
    Rectangle() = default;
    Rectangle(double width, double height);
    std::unique_ptr<Figure> clone() const override;

    double perimeter() const override;
    std::string toString() const override;

    ~Rectangle() override = default;
};