#pragma once
#include "Figure.h"
#include "../stringConverter/stringConvertible.h"
#include <string>

class Circle : public Figure, public stringConvertible {
private:
    double radius = 0;
public:
    Circle() = default;
    Circle(double radius);
    Figure* clone() const override;

    double perimeter() const override;
    std::string toString() const override;

    ~Circle() override = default;
};