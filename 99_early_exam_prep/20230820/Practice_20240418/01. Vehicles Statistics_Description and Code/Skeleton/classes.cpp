#include "classes.h"

using namespace std;


void Vehicle::printInfo(ostream & output) {
    output<<numberPlate<<", "<<color;

    string sizeBuff=getSize();
    string outSize;
    if (sizeBuff=="S") {
        outSize=" with 2 wheels.";
    }
    else if (sizeBuff=="M") {
        outSize=" medium car.";
    }
    else if (sizeBuff=="L") {
        outSize=" bigger car.";
    }
    else if (sizeBuff=="XL") {
        outSize=" truck.";
    }
    else if (sizeBuff=="XXL") {
        outSize=" big truck.";
    };

    output<<outSize;
};



