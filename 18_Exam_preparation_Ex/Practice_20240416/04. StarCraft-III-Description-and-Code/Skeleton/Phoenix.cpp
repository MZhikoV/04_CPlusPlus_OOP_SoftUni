#include "Phoenix.h"
#include <iostream>

// class Phoenix : public ProtossAirShip
// {
//     public:

        Phoenix::Phoenix(const AirShipType type,
                const int         health,
                const int         damage,
                const int         maxShield,
                const int         shieldRegenerateRate,
                const int         shipId)
                : ProtossAirShip(type,health,damage,maxShield,shieldRegenerateRate,shipId) {};

       // virtual Phoenix::~Phoenix() = default;

        void Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip>> & enemyFleet) {
                           
                        enemyFleet.back()->takeDamage(_damage);

                if (!(enemyFleet.back()->isAlive())) {

                          std::string bsName;
                        
                        if (this->getAirShipType()==AirShipType::PHOENIX) {
                                bsName="Phoenix";
                        }
                        else {
                                bsName="Carrier";
                        }
                        std::cout<<bsName<<" with ID: "<<this->getAirShipId()
                        <<" killed enemy warship with ID: "<<(enemyFleet.back())->getAirShipId()<<std::endl;
                        enemyFleet.erase(enemyFleet.end());
                };
        };
