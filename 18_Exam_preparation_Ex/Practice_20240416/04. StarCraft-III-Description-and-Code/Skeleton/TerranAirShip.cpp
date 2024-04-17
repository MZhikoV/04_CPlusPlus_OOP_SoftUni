#include "TerranAirShip.h"

// class TerranAirShip : public AirShip
// {
//     public:
        TerranAirShip::TerranAirShip(const AirShipType type,
                      const int         maxHealth,
                      const int         damage,
                      const int         shipId)
                      : AirShip(type, maxHealth,damage,shipId), _passedTurns(0) {};


        void TerranAirShip::takeDamage(const int damage) {
            _currHealth-=damage;
        };

        void TerranAirShip::finishTurn() {
            _passedTurns++;
        };

