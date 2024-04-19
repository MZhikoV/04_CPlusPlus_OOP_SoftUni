#include <iostream>
#include <string>

#include "CommandExecutor.h"

int main() {
  int commands = 0;
  std::string input;

  std::cin >> commands;
  std::cin.ignore();

  CommandExecutor commandExecutor;

  for (int i = 0; i < commands; ++i) {
    getline(std::cin, input);
    commandExecutor.extractCommand(input);
  }

  system ("pause");
  return 0;
}


/*
10
0 0 50 200 1
0 0 150 250 1
0 0 200 100 2
0 0 100 150 3
4 0
3 0
4 0
2 0
4 0
1 0

*/