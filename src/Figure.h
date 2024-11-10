#pragma once

class Figure {
    public:
    virtual Figure* clone() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Figure() = default;
};