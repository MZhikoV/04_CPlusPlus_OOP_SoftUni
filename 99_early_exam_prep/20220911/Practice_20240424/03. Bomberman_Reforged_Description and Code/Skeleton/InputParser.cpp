#include "InputParser.h"

#include <iostream>
#include <sstream>


  FieldData InputParser::readField() const {
      int rows, cols;
      std::cin>>rows>>cols;
      std::cin.ignore();

      std::string buffer;

      std::vector<std::string> result;

      for (size_t idx=0;idx<rows;idx++) {
        std::getline(std::cin,buffer);
        result.push_back(buffer);
      };
      return result;
  };

  std::vector<Command> InputParser::readCommands() const {
      
      std::vector<Command> commA;

      int commNum;
      std::cin>>commNum;
      std::cin.ignore();      

      while (commNum--) {

        Command c;

        std::string buffer;
        std::getline(std::cin,buffer);

        std::istringstream istr(buffer);

        std::string comm;
        istr>>comm;

        std::string commS;
        istr>>commS;

        if (isalpha(commS[0])) {
          comm+=' '+commS;
        }
        else {
          c.bombRow=stoi(commS);
          istr>>commS;
          c.bombCol=stoi(commS);
        };

        if (comm=="bomb") {
          c.type=CommandType::PLACE_BOMB;
        }
        else if (comm=="power up") {
          c.type=CommandType::POWER_UP;
        }
        else if (comm=="power down") {
          c.type=CommandType::POWER_DOWN;
        }
        else {
          c.type=CommandType::UNKNOWN;
        };

        commA.push_back(c);

      };
    return commA;
  };
