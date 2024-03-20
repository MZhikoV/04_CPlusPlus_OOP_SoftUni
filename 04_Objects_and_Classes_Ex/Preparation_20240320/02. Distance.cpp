#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

class Point {
    private:
    int x,y;

    public:

    Point(istream & istr);

    double getDistance(const Point & other);
};

Point::Point(istream & istr) {
    istr>>x>>y;
}

double Point::getDistance(const Point & other) {
    double dx=this->x-other.x;
    double dy=this->y-other.y;
    
    return sqrt(pow(dx,2)+pow(dy,2));
}




int main() {

    Point p1(cin);
    Point p2(cin);

  //  cout.precision(3);
    cout<<fixed<<setprecision(3);
    cout<<p1.getDistance(p2)<<endl;
    
    system("pause");
    return 0;
}
