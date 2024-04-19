#include "BomberMan.h"

void BomberMan::bombPowerUp() {
  _bombPower++;
}

void BomberMan::bombPowerDown() {
  _bombPower = std::max(0, _bombPower - 1);
}

int BomberMan::placeBomb(const FieldData &fieldData, int bombRow, int bombCol) {
  int score = 0;
  const int rows = fieldData.size();
  const int cols = fieldData[0].size();

  // Check and destroy tiles in horizontal direction
  for (int c = bombCol - _bombPower; c <= bombCol + _bombPower; ++c) {
    if (c >= 0 && c < cols && fieldData[bombRow][c] != 'X') {
      score += fieldData[bombRow][c] - '0';
      fieldData[bombRow][c] = 'X';
    }
  }

  // Check and destroy tiles in vertical direction
  for (int r = bombRow - _bombPower; r <= bombRow + _bombPower; ++r) {
    if (r >= 0 && r < rows && fieldData[r][bombCol] != 'X') {
      score += fieldData[r][bombCol] - '0';
      fieldData[r][bombCol] = 'X';
    }
  }

  return score;
}

int BomberMan::getBombPower() const {
  return _bombPower;
}
