#include "Viking.h"
#include <vector>
#include <iostream>

// class Viking : public TerranAirShip
// {
//     public:


        Viking::Viking(const AirShipType type, const int health, const int baseDamage, const int shipId)
        : TerranAirShip(type,health,baseDamage,shipId) {};

      //  virtual Viking::~Viking() = default;

        void Viking::dealDamage( std::vector<std::unique_ptr<AirShip>> & enemyFleet) {
                if (enemyFleet.back()->getAirShipType()==AirShipType::PHOENIX) {
                        enemyFleet.back()->takeDamage(_damage);
                        enemyFleet.back()->takeDamage(_damage);
                }
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
