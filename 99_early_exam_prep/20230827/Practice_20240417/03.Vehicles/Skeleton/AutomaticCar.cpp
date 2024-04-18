#include "AutomaticCar.h"

// #ifndef AUTOMATICCAR_H_
// #define AUTOMATICCAR_H_

// #include "Car.h"

// class AutomaticCar : public Car {
// public:
  AutomaticCar::AutomaticCar(int maxSpeed, int fuel) : Car(maxSpeed,fuel) {};

  void AutomaticCar::increaseSpeed(int speedIncrease, int fuelConsumtion) {

    Car::increaseSpeed(speedIncrease,fuelConsumtion);
    /*
    currSpeed+=speedIncrease;
    if (currSpeed>maxSpeed) {
      currSpeed=maxSpeed;
    }
    fuel-=fuelConsumtion;
    if (fuel<0) {
      fuel=0;
    };
    */
  };
  
  void AutomaticCar::decreaseSpeed(int speedDecrease) {

    Car::decreaseSpeed(speedDecrease*2);
    // currSpeed-=(speedDecrease*2);
    // if (currSpeed <0) {
    //   currSpeed=0;
    // };
  };
// };



// #endif /* AUTOMATICCAR_H_ */
