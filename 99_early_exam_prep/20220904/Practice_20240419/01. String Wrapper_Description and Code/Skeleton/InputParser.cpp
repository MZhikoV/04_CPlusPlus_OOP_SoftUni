#include "InputParser.h"
#include <iostream>



Input readInput() {
  Input in;
  std::cin>>in.line;
  std::cin>>in.letter;
  std::cin>>in.repetitions;

  return in;
};


