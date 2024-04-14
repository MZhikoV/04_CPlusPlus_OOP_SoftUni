#include "AutomaticCar.h"


  AutomaticCar::AutomaticCar(int maxSpeed, int fuel) : Car(maxSpeed,fuel) {};

  void AutomaticCar::increaseSpeed(int speedIncrease, int fuelConsumtion) override {
       fuel-=fuelConsumtion;
        if (fuel<0) {
            fuel=0;
        };
  };
  void AutomaticCar::decreaseSpeed(int speedDecrease) {

  };
