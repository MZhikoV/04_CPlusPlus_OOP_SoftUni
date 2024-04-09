#include "Glock.h"



		Glock::Glock(const int damagePerRound, const int clipSize, const int remainingAmmo)
		: Pistol (damagePerRound, clipSize, remainingAmmo) {};

		//virtual ~Glock() = default;

		//virtual
		bool Glock::fire(PlayerVitalData & enemyPlayerData) {
			
			int healthDamage=_damagePerRound/2;
			int armorDamage=_damagePerRound/2;

			for (size_t shots=0; shots<ROUNDS_PER_FIRE;shots++) {

				if (_currClipBullets<=0) {
					reload();
					return false;
				};
				
	            _currClipBullets--;

				enemyPlayerData.armor-=armorDamage;

				if (enemyPlayerData.armor<0) {
					enemyPlayerData.health+=enemyPlayerData.armor;
					enemyPlayerData.armor=0;
				};
				
				enemyPlayerData.health-=healthDamage;

				std::cout<<"Enemy left with: "<<enemyPlayerData.health<<" health and "<<enemyPlayerData.armor<<" armor"<<std::endl;

				if (enemyPlayerData.health<=0) {
					return true;
				};
			};
			return false;
		};

	// private:
	// 	enum InternalDefines
	// 	{
	// 		ROUNDS_PER_FIRE = 3
	// 	};