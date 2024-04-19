#ifndef BOMBERMAN_H_
#define BOMBERMAN_H_

#include "Defines.h"

class BomberMan {
public:
  BomberMan() : _bombPower(0) { }

  void bombPowerUp();

  void bombPowerDown();

  int placeBomb(const FieldData &fieldData, int bombRow, int bombCol);

  int getBombPower() const;

private:
  int _bombPower;
};

#endif /* BOMBERMAN_H_ */