#ifndef battlefield_h
#define battlefield_h

#include <vector>
#include <memory>

#include "Hero.h"

class BattleField {

 std::vector<std::unique_ptr<Hero>> _heroes;

public:

BattleField()=default;


void createHeroes();

void createSpells();

void startBattle();

void printWinner(const std::unique_ptr<Hero> &hero);


};

#endif