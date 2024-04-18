#include "ManualCar.h"
#include <algorithm>

// #include <vector>

// class ManualCar : public Car {
// public:
  ManualCar::ManualCar(const std::vector<int>& shiftSpeeds, int maxSpeed, int fuel) : Car(shiftSpeeds,maxSpeed,fuel) {};

  void ManualCar::increaseSpeed(int speedIncrease, int fuelConsumtion) {
      

    int consumption=0;
      int increasedSpeed=currSpeed+speedIncrease;
      if (increasedSpeed>maxSpeed) {
        increasedSpeed=maxSpeed;
      };

      std::vector<int>::iterator it=std::upper_bound(shiftSpeeds.begin(), shiftSpeeds.end(),currSpeed);
      std::vector<int>::iterator itAfter=std::upper_bound(shiftSpeeds.begin(), shiftSpeeds.end(),increasedSpeed);
      std::vector<int>::iterator itAfter_low=std::lower_bound(shiftSpeeds.begin(), shiftSpeeds.end(),increasedSpeed);

      // int faktor=0;
      // if (itAfter==shiftSpeeds.end()) {
      //   faktor=(itAfter_low-it)+1;
      // };
      // // // else {
      // //   faktor=(itAfter-it);
      // // };
      // if (*itAfter>=*it && it!=shiftSpeeds.end() && itAfter!=shiftSpeeds.end()) {
      //     consumption=2*(itAfter-it)*fuelConsumtion;
      // }
      // else if (increasedSpeed>=*it && it!=shiftSpeeds.end()) {
      //     consumption=2*faktor*fuelConsumtion;
      // }
      // else {
      //     consumption=fuelConsumtion;
      // };




      if ((increasedSpeed)>=*it && it!=shiftSpeeds.end()) {
          consumption=2*fuelConsumtion;
      }
      else {
          consumption=fuelConsumtion;
      };


          Car::increaseSpeed(speedIncrease,consumption);
  };

  void ManualCar::decreaseSpeed(int speedDecrease) {
    Car::decreaseSpeed(speedDecrease);
  };

// private:
//   size_t findShiftIdx() const;

//   std::vector<int> _shiftSpeeds;
//   size_t _currShiftIdx { 0 };
// };
