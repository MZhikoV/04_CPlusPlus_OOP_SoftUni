#ifndef car_hh
#define car_hh

#include <vector>

class Car {

public:

Car(int maxSpeed, int fuel) : maxSpeed(maxSpeed), fuel(fuel), currSpeed(0), distance(0) {};

Car(const std::vector<int>& shiftSpeeds, int maxSpeed, int fuel)
: shiftSpeeds(shiftSpeeds), maxSpeed(maxSpeed), fuel(fuel), currSpeed(0), distance(0) {};

virtual void increaseSpeed(int speedIncrease, int fuelConsumtion){
  currSpeed+=speedIncrease;
    if (currSpeed>maxSpeed) {
      currSpeed=maxSpeed;
    }
    fuel-=fuelConsumtion;
    if (fuel<0) {
      fuel=0;
      currSpeed=0;
    };
};

virtual void decreaseSpeed(int speedDecrease) {
  currSpeed-=(speedDecrease);
    if (currSpeed <0) {
      currSpeed=0;
    };
};





public:
int maxSpeed;
int fuel;
int currSpeed;
std::vector<int> shiftSpeeds;
int distance;

};









/*
#ifndef AUTOMATICCAR_H_
#define AUTOMATICCAR_H_

#include "Car.h"

class AutomaticCar : public Car {
public:
  AutomaticCar(int maxSpeed, int fuel);

  void increaseSpeed(int speedIncrease, int fuelConsumtion) final;
  void decreaseSpeed(int speedDecrease) final;
};

#endif /* AUTOMATICCAR_H_ */

/*
#ifndef MANUALCAR_H_
#define MANUALCAR_H_

#include "Car.h"

#include <vector>

class ManualCar : public Car {
public:
  ManualCar(const std::vector<int>& shiftSpeeds, int maxSpeed, int fuel);

  void increaseSpeed(int speedIncrease, int fuelConsumtion) final;
  void decreaseSpeed(int speedDecrease) final;

private:
  size_t findShiftIdx() const;

  std::vector<int> _shiftSpeeds;
  size_t _currShiftIdx { 0 };
};

#endif /* MANUALCAR_H_ */

#endif