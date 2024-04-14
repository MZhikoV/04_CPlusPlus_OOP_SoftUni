#ifndef car_h
#define car_h

class Car {
    
    int maxSpeed;
    int fuel;

protected:
    int currSpeed;
    int currDist;
public:

    Car (int maxSpeed, int fuel) : maxSpeed(maxSpeed), fuel(fuel), currSpeed(0), currDist(0) {};

    virtual void increaseSpeed(int speedIncrease, int fuelConsumtion) {
        currSpeed+=speedIncrease;
        if (currSpeed>maxSpeed) {
            currSpeed=maxSpeed;
        };
    };
    virtual void decreaseSpeed(int speedDecrease) {
        currSpeed-=2*speedDecrease;
        if (currSpeed<0) {
            currSpeed=0;
        };
    };
};


#endif