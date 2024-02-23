#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;



int main() {
    enum planets {earth=3,mars,jupiter,saturn, uranus, neptune};

    //we can do maths with this enum, because it is just const int underneath
    cout<<"earth ("<<earth<<") is "<<uranus-earth<<" planets away from uranus ("<<uranus<<")"<<endl;


    enum class Planets {earth=3,mars,jupiter,saturn, uranus, neptune};

    Planets planetEarth=Planets::earth;

    enum class PlanetsChar: char {earth='e',mars='m',jupiter='j', saturn='s',uranus='u', neptune='n'};

    PlanetsChar planetEarthChar =PlanetsChar::earth;

    cout<<(char) planetEarthChar<<endl;

 //   cout<<planetEarthChar<<endl;
    
    
    system("pause");
    return 0;
}
