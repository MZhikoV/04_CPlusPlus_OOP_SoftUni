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
4
0 0 200 100 1
0 0 100 150 1
3 0
4 0

*/

/*
6
0 1 200 100
0 1 100 150
0 1 100 150
0 1 100 150
3 1
4 1



*/