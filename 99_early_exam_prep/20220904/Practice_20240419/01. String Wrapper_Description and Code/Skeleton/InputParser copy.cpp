//#include "InputParser.h"
#include <iostream>

#include <string>

struct Input {
  std::string line;
  char letter {};
  int repetitions {};
};

Input readInput() {
  Input in;
  std::cin>>in.line;
  std::cin>>in.letter;
  std::cin>>in.repetitions;

  return in;
};


