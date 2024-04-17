#include "BattleCruser.h"
#include <iostream>
#include<string>

// class BattleCruser : public TerranAirShip
// {
//     public:
        BattleCruser::BattleCruser(const AirShipType type,
                     const int         health,
                     const int         damage,
                     const int         shipId) 
                     : TerranAirShip (type,health,damage,shipId) {};

      //  virtual ~BattleCruser() = default;

        void BattleCruser::dealDamage(
                  std::vector<std::unique_ptr<AirShip>> & enemyFleet) {
                     if (this->_passedTurns==BattleCruserDefines::YAMATO_CANNON_LOADING_TIME) {
                        enemyFleet.back()->takeDamage(_damage*5);
                        _passedTurns=-1;
                    }
                    // if (_passedTurns%5==0) {
                    //     enemyFleet.back()->takeDamage(_damage*5);
                    // }
                else {                
                        enemyFleet.back()->takeDamage(_damage);
                };

                if (!(enemyFleet.back()->isAlive())) {
                        std::string bsName;
                        if (this->getAirShipType()==AirShipType::BATTLE_CRUSER) {
                                bsName="Battlecruiser";
                        }
                        else {
                                bsName="Viking";
                        };
                        
                        std::cout<<bsName<<" with ID: "<<this->getAirShipId()
                        <<" killed enemy warship with ID: "<<(enemyFleet.back())->getAirShipId()<<std::endl;
                        enemyFleet.erase(enemyFleet.end());
                };

                  };

    // private:
    //     enum BattleCruserDefines
    //     {
    //         YAMATO_CANNON_LOADING_TIME = 4 //4 turns and shoots on the 5th
    //     };

