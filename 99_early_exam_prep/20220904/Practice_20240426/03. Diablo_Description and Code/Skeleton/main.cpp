#include "BattleField.h"

int main() {
  BattleField battleField;
  battleField.createHeroes();
  battleField.createSpells();
  battleField.startBattle();

  system("pause");

  return EXIT_SUCCESS;
}
