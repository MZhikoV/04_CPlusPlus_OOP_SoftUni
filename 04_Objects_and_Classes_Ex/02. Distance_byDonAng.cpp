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

    double distance(Point & other); //method calling another object
};

double Point::distance(Point &other) {      //method calling another object
    int dx=this->x-other.x;                 //this->x is the value for the current object (method caller), other.x is the value of the called object
    int dy=this->y-other.y;
    return sqrt(pow(dx,2)+pow(dy,2));       //return the value
}



int main() {

    Point p1(cin); //creating first object p1
    Point p2(cin); //creating secind object p2

    cout<<fixed<<setprecision(3)<<p1.distance(p2)<<endl; //printing the value to the console with fixed digits (3) after the decimal separator
    
    
    system("pause");
    return 0;
}
