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
    typedef int Coord;
    Coord x,y;

    public:
    Point () : x(0), y(0) {};
    Point (istream & istr);

    double getDist(Point & somepoint);
};

Point::Point(istream & istr) {
    istr>>x>>y;
}

double Point::getDist(Point & somepoint) {
    double dx=this->x-somepoint.x;
    double dy=this->y-somepoint.y;

    return sqrt(pow(dx,2)+pow(dy,2));
}



int main() {

    Point p1(cin);
    Point p2(cin);

    cout<<fixed<<setprecision(3)<<p1.getDist(p2)<<endl;
    
    
    system("pause");
    return 0;
}
