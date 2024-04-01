#include <iostream>
#include <math.h>
#include <iomanip>


using namespace std;

int main() {

class Point {
    int x;
    int y;

    public:
    Point()=default;
    Point(int num1, int num2) : x(num1), y(num2) {};

    void getDistance(Point a, Point b) {
        double result=sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
        cout<<fixed<<setprecision(3)<< result<<endl;
    };
};

int x1,y1,x2,y2;
cin>>x1>>y1>>x2>>y2;
Point a(x1,y1);
Point b(x2,y2);

Point c;
c.getDistance(a,b);

    system("pause");
    return 0;
}