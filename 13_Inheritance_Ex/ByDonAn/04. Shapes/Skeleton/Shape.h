#ifndef SHAPE_H
#define SHAPE_H

#include "Vector2D.h"

class Shape {

    protected:
        Vector2D center;
        double area;

    public:
    Shape(const Vector2D & center=Vector2D(0,0)): center(center), area(0) {};

    const Vector2D & getCenter() const {
        return center;
    };

    double getArea() const {
        return area;
    };


};


#endif