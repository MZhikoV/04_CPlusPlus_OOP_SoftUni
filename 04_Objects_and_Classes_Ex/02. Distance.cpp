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

using namespace std;

class Distance {
    private:
        int x1;
        int x2;
        int y1;
        int y2;

    public:
        Distance () {};

        void setPoints(int a, int b, int c, int d) {
            this->x1=a;
            this->x2=c;
            this->y1=b;
            this->y2=d;
        }

        double getDist();


};

double Distance::getDist() {
    double dist=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    return dist;
};


int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    Distance dist1;

    dist1.setPoints(a,b,c,d);

    cout.setf(ios::fixed);
    cout.precision(3);

    cout<<dist1.getDist()<<endl;
    
    system("pause");
    return 0;
}
