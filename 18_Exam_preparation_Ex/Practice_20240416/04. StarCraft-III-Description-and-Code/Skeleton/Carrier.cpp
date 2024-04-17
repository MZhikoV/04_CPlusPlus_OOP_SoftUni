#include "Carrier.h"
#include <iostream>
#include<string>
// class Carrier : public ProtossAirShip
// {
//     public:
        Carrier::Carrier(const AirShipType type,
                const int         health,
                const int         damage,
                const int         maxShield,
                const int         shieldRegenerateRate,
                const int         shipId)
                : ProtossAirShip(type,health,damage,maxShield,shieldRegenerateRate,shipId) {};

     //   virtual ~Carrier() = default;

        void Carrier::takeDamage(const int damage) {
            ProtossAirShip::takeDamage(damage);
        };

        void Carrier::dealDamage(
                  std::vector<std::unique_ptr<AirShip>> & enemyFleet) {
                     if (this->_currHealth<_maxHealth) {
                        enemyFleet.back()->takeDamage(_damage*4);
                     }
                     else {
                     enemyFleet.back()->takeDamage(_damage*8);
                     };

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

//     private:
//         enum InterceptorDefines
//         {
//             MAX_INTERCEPTORS            = 8,
//             DAMAGED_STATUS_INTERCEPTORS = 4
//         };

//         int _activeInterceptors;
// };

// #endif /* CARRIER_H_ */
