#include <memory>
#include <vector>
#include <utility>
#include <iostream>

#include "Car.h"
#include "RaceTrack.h"
#include "AutomaticCar.h"
#include "ManualCar.h"

// class RaceTrack {
// public:
  bool RaceTrack::isRaceRunning() const{
    for (size_t idx=0; idx<_cars.size(); idx++) {
      if (_cars[idx]->fuel==0) {
        return false;
      };
    };

    return true;
  };

  void RaceTrack::printWinner() {
      if (_cars[0]->fuel==0 && _cars[1]->fuel==0) {
        if (_cars[0]->distance==_cars[1]->distance ) {
          std::cout<<"No winner"<<std::endl;
        }
        else if (_cars[0]->distance>_cars[1]->distance ) {
          std::cout<<"Car with index: 0 won!"<<std::endl;
        }
        else {
          std::cout<<"Car with index: 1 won!"<<std::endl;
        };
      }
      else if (_cars[0]->fuel==0) {
          std::cout<<"Car with index: 1 won!"<<std::endl;
      }
      else if (_cars[1]->fuel==0){
          std::cout<<"Car with index: 0 won!"<<std::endl;
      }
      else {
        if (_cars[0]->distance==_cars[1]->distance ) {
          std::cout<<"No winner"<<std::endl;
        }
        else if (_cars[0]->distance>_cars[1]->distance ) {
          std::cout<<"Car with index: 0 won!"<<std::endl;
        }
        else {
          std::cout<<"Car with index: 1 won!"<<std::endl;
        };
      }
  };

  void RaceTrack::createManualCar(const std::vector<int> &shifts, int maxSpeed,
                       int startFuel) {
_cars.push_back(std::make_unique<ManualCar>(shifts, maxSpeed, startFuel));                       };

  void RaceTrack::createAutomaticCar(int maxSpeed, int startFuel) {

    _cars.push_back(std::make_unique<AutomaticCar>(maxSpeed, startFuel));
    };

  void RaceTrack::increaseSpeed(int speedIncrease, int fuelConsumtion) {
    for (size_t idx=0; idx<_cars.size(); idx++) {
      _cars[idx]->increaseSpeed(speedIncrease,fuelConsumtion);
    }
    //todo
  };

  void RaceTrack::decreaseSpeed(int speedDecrease) {
    //todo
    for (size_t idx=0; idx<_cars.size(); idx++) {
      _cars[idx]->decreaseSpeed(speedDecrease);
    }
  };

  void RaceTrack::advance() {
    for (size_t idx=0; idx<_cars.size(); idx++) {
      _cars[idx]->distance+=_cars[idx]->currSpeed;
    }
  };

  void RaceTrack::printInfo() const {
    
    for (size_t idx=0; idx<_cars.size(); idx++) {

      std::cout<<"Car with index: "<<idx<<" has totalDistance: "<<_cars[idx]->distance<<", is running with "
      <<_cars[idx]->currSpeed<<" speed, has "<<_cars[idx]->fuel<<" fuel left"<<std::endl;
    };

  };

// private:
//   std::vector<std::unique_ptr<Car>> _cars;
// };
