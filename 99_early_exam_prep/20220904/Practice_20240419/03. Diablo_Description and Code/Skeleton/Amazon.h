#ifndef Amazon_h
#define Amazon_h


#include "Structs.h"
#include "Hero.h"

class Amazon:public Hero {

VitalData dataA;
std::array<SpellData, SPELLS_COUNT> _spells;
int arrCount=0;
int attack=1;
//std::string _name;


public:


    Amazon(VitalData data) : dataA(data) {Hero::_name=AMAZON_NAME;};

    void readSpellFromInput(SpellType spellType) override {
        SpellData sbw;
        if (spellType==SpellType::Weak) {
            std::cin>>sbw.name;
            std::cin>>sbw.damage;
        }
        else {
            std::cin>>sbw.name;
            std::cin>>sbw.damage;
            std::cin>>sbw.manaCost;
        }

        _spells[arrCount]=sbw;

        arrCount++;

    };


       //returns the produced damage
    int castSpell() override {
        double factor=1;
        int dmg=0;
    
        // if ((attack%(HeroDefines::AMAZON_PASSIVE_ABILITY_COUNTER))==0) {
        //     factor=(1+(HeroDefines::AMAZON_DAMAGE_INCREASE_PERCENT/100));
        // };

        if (attack%2==0) {
            factor=1.25;
        }
            attack++;

            std::cout<<Hero::_name<<" casting ";

        if (dataA.currMana>=_spells[SpellDefines::STRONGER_SPELL].manaCost) {

            std::cout<<_spells[SpellDefines::STRONGER_SPELL].name<<" for "<<_spells[SpellDefines::STRONGER_SPELL].manaCost<<" mana"<<std::endl;

            dataA.currMana-=_spells[SpellDefines::STRONGER_SPELL].manaCost;

            dmg=factor*(_spells[SpellDefines::STRONGER_SPELL].damage);

            return dmg;
            
            //return (_spells[SpellDefines::STRONGER_SPELL].damage*factor);
        }
        else {

            std::cout<<_spells[SpellDefines::WEAKER_SPELL].name<<" for 0 mana"<<std::endl;

            dmg=factor*(_spells[SpellDefines::WEAKER_SPELL].damage);
            // std::cout<<"damage "<<dmg<<std::endl;

            return dmg;

            //return  (_spells[SpellDefines::WEAKER_SPELL].damage*factor);
        };
    };

    void takeDamage(int damage) override {

        dataA.health-=damage;

        // if (dataA.health<=0) {
        //     dataA.health=0;
        // };


        std::cout<<Hero::_name<<" took "<<damage<<" damage and is left with "<<dataA.health<<" health"<<std::endl;
    };

     void regenerate() {
        int regenerated=dataA.currMana;
        dataA.currMana+=dataA.manaRegenRate;
        if (dataA.currMana>dataA.maxMana) {
            dataA.currMana=dataA.maxMana;
        };

        regenerated=dataA.currMana-regenerated;

        std::cout<<Hero::_name<<" regained "<<regenerated<<" mana for up to "<<dataA.currMana<<std::endl;
    };

    bool isDead() const {
        if (dataA.health<=0) {
            return true;
        }
        else {
            return false;
        }
    };

};


#endif