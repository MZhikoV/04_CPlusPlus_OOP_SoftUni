#include <iostream>
#include <cmath>
#include <iomanip>

class Point {
    double xx;
    double yy;

    public:
    Point(double x, double y):xx(x),yy(y) {};

    double getX() {
        return xx;
    };

    double getY() {
        return yy;
    };
};

class dist {
    Point a;
    Point b;

    public:
    dist(Point a, Point b): a(a), b(b) {};

    double getDist() {
        return sqrt(pow((a.getX()-b.getX()),2)+pow((a.getY()-b.getY()),2));
    };
};

Point readInp() {
    double x,y;
    std::cin>>x>>y;
    Point tmp(x,y);
    return tmp;
}

int main() {
    Point a=readInp();
    Point b=readInp();
    dist c(a,b);

    std::cout<<std::fixed<<std::setprecision(3);
    std::cout<<c.getDist()<<std::endl;

    system("pause");
    return 0;

}