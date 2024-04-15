#ifndef shapee_h
#define shapee_h

#include "Vector2D.h"

#include <sstream>
#include <string>


class Shape {

Vector2D center;

protected:
    double area;

public:
    Shape(): center(0,0), area(0) {};
    Shape(Vector2D center): center(center), area(0) {};



   std::string getCenter() const {
    return std::string(center);
   };

   double getArea() const {
    return area;
   };


};



#endif