#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <math.h>
#include <iomanip>

using namespace std;

class Point{
    typedef int Coord; //type of the coordinates

    Coord x=0,y=0; //coordinates of a point

    public:

    Point() {};
    Point(istream &istr) {
        istr>>x>>y; //assigning values to the piint coordinates by using the input stream
    }

    double distance(Point & other);
};

double Point::distance(Point &other) {
    int dx=this->x-other.x;
    int dy=this->y-other.y;
    return sqrt(pow(dx,2)+pow(dy,2));
}



int main() {

    Point p1(cin);
    Point p2(cin);

    cout<<fixed<<setprecision(3)<<p1.distance(p2)<<endl;
    
    
    system("pause");
    return 0;
}
