#ifndef Barbarian_h
#define Barbarian_h


#include "Structs.h"
#include "Hero.h"


class Barbarian:public Hero {

VitalData dataB;
std::array<SpellData, SPELLS_COUNT> _spells;
int arrCount=0;
int block=1;
//std::string _name;


public:

    Barbarian(VitalData data) : dataB(data) {Hero::_name=BARBARIAN_NAME;};

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

        std::cout<<Hero::_name<<" casting ";

        if (dataB.currMana>=_spells[SpellDefines::STRONGER_SPELL].manaCost) {

            std::cout<<_spells[SpellDefines::STRONGER_SPELL].name<<" for "<<_spells[SpellDefines::STRONGER_SPELL].manaCost<<" mana"<<std::endl;

            dataB.currMana-=_spells[SpellDefines::STRONGER_SPELL].manaCost;

            return _spells[SpellDefines::STRONGER_SPELL].damage;
        }
        else {

            std::cout<<_spells[SpellDefines::WEAKER_SPELL].name<<" for 0 mana"<<std::endl;

            return  _spells[SpellDefines::WEAKER_SPELL].damage;
        };
    };


    void takeDamage(int damage) override {

        // if (block%(HeroDefines::BARBARIAN_PASSIVE_ABILITY_COUNTER)==0) {
        //     damage*=(HeroDefines::BARBARIAN_DAMAGE_BLOCK_PERCENT/100);
        // }

        if (block%3==0) {
            damage*=0.5;
        }

        //std::cout<<"damage to take "<<damage<<std::endl;

        dataB.health-=damage;

        // if (dataB.health<=0) {
        //     dataB.health=0;
        // };

        block++;

        std::cout<<Hero::_name<<" took "<<damage<<" damage and is left with "<<dataB.health<<" health"<<std::endl;
    };


    void regenerate() {
        int regenerated=dataB.currMana;
        dataB.currMana+=dataB.manaRegenRate;
        if (dataB.currMana>dataB.maxMana) {
            dataB.currMana=dataB.maxMana;
        };

        regenerated=dataB.currMana-regenerated;

        std::cout<<Hero::_name<<" regained "<<regenerated<<" mana for up to "<<dataB.currMana<<std::endl;
    };


    bool isDead() const {
        if (dataB.health<=0) {
            return true;
        }
        else {
            return false;
        }
    };
};


#endif