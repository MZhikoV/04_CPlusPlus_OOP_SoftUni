#ifndef Amazon_h
#define Amazon_h

#include "Hero.h"

class Amazon:public Hero {
    //todo
    VitalData amz;
    size_t attack;

    void castd(const std::string & _name, const std::string & nameSpell, const int & mana) {
        std::cout<<_name<<" casting "<<nameSpell<<" for "<<mana<<" mana"<<std::endl;
    };

public:
    Amazon(const VitalData & data) : amz(data) { _name="Amazon", attack=0;}; 

    virtual int castSpell() override {
        attack++;
        int damage=0;
        if (amz.currMana>=_spells[STRONGER_SPELL].manaCost) {
            amz.currMana-=_spells[STRONGER_SPELL].manaCost;
            castd(_name,_spells[STRONGER_SPELL].name,_spells[STRONGER_SPELL].manaCost);
            damage= _spells[STRONGER_SPELL].damage;
        }
        else {
            castd(_name,_spells[WEAKER_SPELL].name,_spells[WEAKER_SPELL].manaCost);
            damage= _spells[WEAKER_SPELL].damage;
        };
        if (attack%2==0) {
            damage*=1.25;
        };
        return damage;
     };

    virtual void takeDamage(int damage) override {
        amz.health-=damage;
        std::cout<<_name<<" took "<<damage<<" damage and is left with "<<amz.health<<" health"<<std::endl;
        //“Hero took D damage and is left with H health”
    };

    virtual void regenerate() override {
        int curr = amz.currMana;

        amz.currMana+=amz.manaRegenRate;
        if (amz.currMana>amz.maxMana) {
            amz.currMana=amz.maxMana;
        }
        std::cout<<_name<<" regained "<<amz.currMana-curr<<" mana for up to "<<amz.currMana<<std::endl;
    };

    virtual bool isDead() const override {
        if (amz.health<=0) {
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