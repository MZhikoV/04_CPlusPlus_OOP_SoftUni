#ifndef battflefield_h
#define battflefield_h

#include <cstdlib>
#include <vector>
#include <memory>

#include "Hero.h"


class BattleField {




public:

    std::vector<std::unique_ptr<Hero>>_heroes;

    void createHeroes();

    void createSpells();

    void startBattle();

    void printWinner(const std::unique_ptr<Hero> &hero);
};




#endif