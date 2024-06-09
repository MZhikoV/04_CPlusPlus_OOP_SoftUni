#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Point {
    double x;
    double y;

public:

    Point (istream & istr) {
        istr>>x>>y;
    };

    void distance( Point & other) const {
        cout<<fixed<<setprecision(3)<<sqrt(pow((this->x-other.x),2)+pow((this->y-other.y),2))<<endl;
    };
};

int main() {

    Point one(cin);
    Point two(cin);

    one.distance(two);

    system("pause");
    return 0;
}