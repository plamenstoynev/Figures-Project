#pragma once
#include <string>
#include "Figure.h"
#include "../stringConverter/stringConvertible.h"

class Triangle : public Figure, public stringConvertible{
private:
    double a = 0;
    double b = 0;
    double c = 0;
public:
    Triangle() = default;
    Triangle(double a,double b,double c);
    std::unique_ptr<Figure> clone() const override;

    double perimeter() const override;
    std::string toString() const override;

    static std::vector<double> correctTriangleSides();

    ~Triangle() override = default;
};