#ifndef BomberMan_h
#define BomberMan_h

#include <vector>
#include <string>
#include<iostream>

#include "Field.h"

class BomberMan {

  void callme(std::vector<std::string> &battlefield) {
    for(int i=0; i<battlefield.size();i++) {
            std::cout<<battlefield[i]<<std::endl;
        };
    };

int bombPower =0;
std::vector<std::vector<char>> comp;

Field tryvec;

public:

void bombPowerUp() {
    bombPower++;
};

void bombPowerDown() {
    bombPower--;
    if (bombPower<0) {
        bombPower=0;
    };
};

int getBombPower() const {
    return bombPower;
};

int placeBomb(const FieldData & gettedFeildData, int bombRow, int bombCol) {
    int result=0;

  //  FieldData battlefield=gettedFeildData;
  if (tryvec.battlefield.empty()) {
    tryvec.populateField(gettedFeildData);
  }
    FieldData battlefield=tryvec.getFieldData();
    

        //current position
        result+=(battlefield[bombRow][bombCol]-'0');
        battlefield[bombRow][bombCol]='0';

        //horizontal elements
        for (int i=1;i<=bombPower;i++) {
            if (bombRow-i>=0) {
                result+=(battlefield[bombRow-i][bombCol]-'0');
                battlefield[bombRow-i][bombCol]='0';
            };
            if (bombRow+i<=battlefield.size()-1) {
                result+=(battlefield[bombRow+i][bombCol]-'0');
                battlefield[bombRow+i][bombCol]='0';
            };
        };

        //for vertical elements
        for (int i=1;i<=bombPower;i++) {
            if (bombCol-i>=0) {
                result+=(battlefield[bombRow][bombCol-i]-'0');
                battlefield[bombRow][bombCol-i]='0';
            };
            if (bombCol+i<=battlefield[bombRow].size()-1) {
                result+=(battlefield[bombRow][bombCol+i]-'0');
                battlefield[bombRow][bombCol+i]='0';
            };
        };

    //const_cast<FieldData &>(gettedFeildData)=battlefield;
     tryvec.populateField(battlefield);


    return result;
};



};


#endif