#include <iostream>
#include <vector>

#include "TerranAirShip.h"

        TerranAirShip::TerranAirShip(const AirShipType type,
                      const int         maxHealth,
                      const int         damage,
                      const int         shipId)
                      : AirShip(type, maxHealth,damage,shipId), _passedTurns(1) {};
                      // turns initialised with 1


        void TerranAirShip::takeDamage(const int damage) {
            _currHealth-=damage;
        };

        void TerranAirShip::finishTurn() {
            _passedTurns++;
        };




#include "ProtossAirShip.h"

        ProtossAirShip::ProtossAirShip(const AirShipType type,
                       const int         health,
                       const int         damage,
                       const int         maxShield,
                       const int         shieldRegenerateRate,
                       const int         shipId)
                       : AirShip(type,health,damage,shipId), _maxShield(maxShield), 
                       _currShield(maxShield), _shieldRegenerateRate(shieldRegenerateRate) {};


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
            _currShield+=_shieldRegenerateRate;

            if(_currShield>_maxShield) {
                _currShield=_maxShield;
            };
        };


#include "Phoenix.h"

        Phoenix::Phoenix(const AirShipType type,
                const int         health,
                const int         damage,
                const int         maxShield,
                const int         shieldRegenerateRate,
                const int         shipId)
                : ProtossAirShip(type,health,damage,maxShield,shieldRegenerateRate,shipId) {};

        void Phoenix::dealDamage(std::vector<std::unique_ptr<AirShip>> & enemyFleet) {
                           
            AirShip * victim=enemyFleet.back().get();

            victim->takeDamage(_damage);

            if (!victim->isAlive()) {
                std::cout<<"Phoenix with ID: "<<this->getAirShipId()<<" killed enemy airship with ID: "
                <<victim->getAirShipId()<<std::endl;

               enemyFleet.pop_back();
            };
        };


#include "Viking.h"

        Viking::Viking(const AirShipType type, const int health, const int baseDamage, const int shipId)
        : TerranAirShip(type,health,baseDamage,shipId) {};


        void Viking::dealDamage( std::vector<std::unique_ptr<AirShip>> & enemyFleet) {

            AirShip * victim=enemyFleet.back().get();

            victim->takeDamage(_damage);

            if (enemyFleet.back()->getAirShipType()==AirShipType::PHOENIX) {
                victim->takeDamage(_damage);
            };

             if (!victim->isAlive()) {
                std::cout<<"Viking with ID: "<<this->getAirShipId()<<" killed enemy airship with ID: "
                <<victim->getAirShipId()<<std::endl;

               enemyFleet.pop_back();
            };
        };


#include "BattleCruser.h"

        BattleCruser::BattleCruser(const AirShipType type,
                     const int         health,
                     const int         damage,
                     const int         shipId) 
                     : TerranAirShip (type,health,damage,shipId) {};


        void BattleCruser::dealDamage(
                  std::vector<std::unique_ptr<AirShip>> & enemyFleet) {

                    AirShip * victim=enemyFleet.back().get();

                    if(_passedTurns%(YAMATO_CANNON_LOADING_TIME+1)==0) {
                        victim->takeDamage(_damage*5);
                    }
                    else {
                    victim->takeDamage(_damage);
                    };

                    if (!victim->isAlive()) {
                        std::cout<<"BattleCruser with ID: "<<this->getAirShipId()<<" killed enemy airship with ID: "
                        <<victim->getAirShipId()<<std::endl;

                    enemyFleet.pop_back();
                    };
                  };



#include "Carrier.h"

        Carrier::Carrier(const AirShipType type,
                const int         health,
                const int         damage,
                const int         maxShield,
                const int         shieldRegenerateRate,
                const int         shipId)
                : ProtossAirShip(type,health,damage,maxShield,shieldRegenerateRate,shipId),
                _activeInterceptors(MAX_INTERCEPTORS) {};

        void Carrier::takeDamage(const int damage) {
            ProtossAirShip::takeDamage(damage);
            if(_currHealth<_maxHealth) {
                _activeInterceptors=DAMAGED_STATUS_INTERCEPTORS;
            }
        };

    bool carrDMG(AirShip* attacker,int _damage, std::vector<std::unique_ptr<AirShip>> & enemyFleet) {
        AirShip * victim=enemyFleet.back().get();

        victim->takeDamage(_damage);

        if (!victim->isAlive())
                        {
                            std::cout << "Carrier with ID: " << attacker->getAirShipId() << " killed enemy airship with ID: "
                                      << victim->getAirShipId() << std::endl;

                            enemyFleet.pop_back();
                            return true;
                        };
                        return false;
    };





        void Carrier::dealDamage(std::vector<std::unique_ptr<AirShip>> & enemyFleet) {

                    for (size_t curr = 0; curr < _activeInterceptors; curr++) {
                        
                        carrDMG(this,_damage,enemyFleet);

                            if (enemyFleet.size() == 0)
                            {
                                return;
                            };
                        };
                    };







                    // AirShip * victim=enemyFleet.back().get();

                    // for (size_t curr = 0; curr < _activeInterceptors; curr++)
                    // {

                    //     victim->takeDamage(_damage);
                    //     std::cout << victim->getAirShipId() << ' ' << victim->getCurrHealth() << std::endl;

                    //     if (!victim->isAlive())
                    //     {
                    //         std::cout << "Carrier with ID: " << this->getAirShipId() << " killed enemy airship with ID: "
                    //                   << victim->getAirShipId() << std::endl;

                    //         enemyFleet.pop_back();

                    //         if (enemyFleet.size() == 0)
                    //         {
                    //             return;
                    //         };

                    //         *victim = enemyFleet.back().get();
                    //         std::cout << victim->getAirShipId() << std::endl;
                    //     };
                    // };

