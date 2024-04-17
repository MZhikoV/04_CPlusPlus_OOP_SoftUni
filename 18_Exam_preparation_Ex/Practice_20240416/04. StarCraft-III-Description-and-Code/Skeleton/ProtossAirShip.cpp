#include "ProtossAirShip.h"

// class ProtossAirShip : public AirShip
// {
//     public:
        ProtossAirShip::ProtossAirShip(const AirShipType type,
                       const int         health,
                       const int         damage,
                       const int         maxShield,
                       const int         shieldRegenerateRate,
                       const int         shipId)
                       : AirShip(type,health,damage,shipId), _maxShield(maxShield), 
                       _currShield(maxShield), _shieldRegenerateRate(shieldRegenerateRate) {};

        //virtual ~ProtossAirShip() = default;

        void ProtossAirShip::takeDamage(const int damage) {
            if(_currShield>damage) {
                _currShield-=damage;
            }
            else {
                int temp=damage;
                temp-=_currShield;
                _currShield=0;
                _currHealth-=temp;
            };
        };

        void ProtossAirShip::finishTurn() {
            // if (this->getAirShipType()==AirShipType::PHOENIX) {
            //     _currShield+=(_shieldRegenerateRate);
            // }
            // else {
            // _currShield+=_shieldRegenerateRate;
            // };
            
            _currShield+=_shieldRegenerateRate;

            if(_currShield>_maxShield) {
                _currShield=_maxShield;
            };
        };

    // protected:
    //     int _maxShield;
    //     int _currShield;
    //     int _shieldRegenerateRate;
