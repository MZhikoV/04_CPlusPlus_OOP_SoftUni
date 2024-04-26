#ifndef Barbarian_h
#define Barbarian_h

#include "Hero.h"


class Barbarian : public Hero {
    //todo

     //todo
    VitalData brb;

    size_t attacked;

    void castd(const std::string & _name, const std::string & nameSpell, const int & mana) {
        std::cout<<_name<<" casting "<<nameSpell<<" for "<<mana<<" mana"<<std::endl;
    };

public:
    Barbarian(const VitalData & data) : brb(data) { _name="Barbarian", attacked=0;}; 

    virtual int castSpell() override {
        if (brb.currMana>=_spells[STRONGER_SPELL].manaCost) {
            brb.currMana-=_spells[STRONGER_SPELL].manaCost;
            castd(_name,_spells[STRONGER_SPELL].name,_spells[STRONGER_SPELL].manaCost);
            return _spells[STRONGER_SPELL].damage;
        }
        else {
            castd(_name,_spells[WEAKER_SPELL].name,_spells[WEAKER_SPELL].manaCost);
            return _spells[WEAKER_SPELL].damage;
        };
     };

    virtual void takeDamage(int damage) override {
        attacked++;
        if (attacked%3==0) {
            damage*=0.5;
        };

        brb.health-=damage;
        std::cout<<_name<<" took "<<damage<<" damage and is left with "<<brb.health<<" health"<<std::endl;
    };

    virtual void regenerate() override {
        int curr=brb.currMana;
        brb.currMana+=brb.manaRegenRate;
        if (brb.currMana>brb.maxMana) {
            brb.currMana=brb.maxMana;
        }
        std::cout<<_name<<" regained "<<brb.currMana-curr<<" mana for up to "<<brb.currMana<<std::endl;
        //“Hero egained M mana for up to T”
    };

    virtual bool isDead() const override {
        if (brb.health<=0) {
            return true;
        }
        else {
            return false;
        };
    };

    virtual void readSpellFromInput(SpellType spellType) override {
        SpellData a;
        std::cin>>a.name>>a.damage;
        if (spellType!=SpellType::Weak) {
            std::cin>>a.manaCost;
            _spells[STRONGER_SPELL]=a;
        }
        else {
            _spells[WEAKER_SPELL]=a;
        };
    };

};



#endif