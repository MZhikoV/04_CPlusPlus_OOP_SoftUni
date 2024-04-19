#include "InputParser.h"
#include "Field.h"

#include <iostream>
#include <sstream>


  FieldData InputParser::readField() const {
   // Field ff;
      int rows, cols;
      std::cin>>rows>>cols;
      std::cin.ignore();

      std::string buffer;

      std::vector<std::string> result;

      for (size_t idx=0;idx<rows;idx++) {
        std::getline(std::cin,buffer);
        result.push_back(buffer);
      };
     // std::vector<std::string> result=ff.getFieldData();
      
    return result;
  };

  std::vector<Command> InputParser::readCommands() const {
      int comNum;
      std::cin>>comNum;
      std::cin.ignore();
      
        //Command cm;
        std::vector<Command> result;

      std::string buffer;
      while (comNum--) {
        std::getline(std::cin,buffer);
        std::istringstream istr(buffer);

        Command cm;

        std::string cmdType;
        istr>>cmdType;

        std::string addType;
        istr>>addType;

        if (isalpha(addType[0])) {
            cmdType+=(' '+addType);
        }
        else {
            cm.bombRow=stoi(addType);
            istr>>cm.bombCol;
        };

        if (cmdType=="bomb") {
          cm.type=CommandType::PLACE_BOMB;
        }
        else if (cmdType=="power up") {
          cm.type=CommandType::POWER_UP;
        }
        else if (cmdType=="power down") {
          cm.type=CommandType::POWER_DOWN;
        }
        else {
          cm.type=CommandType::UNKNOWN;
        };

        result.push_back(cm);     
        
      }     
      return result;
  };

