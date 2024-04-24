#ifndef bomberman_h
#define bomberman_h

#include "Field.h"


class BomberMan {

    int power=0;

    public:
        BomberMan()=default;

    void bombPowerUp() {
        power++;
    };

    int getBombPower() const {
        return power;
    };

    void bombPowerDown() {
        power--;
        if (power<0) {
            power==0;
        };
    };

    Field currfield;
    

    int placeBomb(const FieldData & data, int & bombRow, int & bombCol) {
        
        

        FieldData currBattle;

        if (currBattle.empty()) {
            currBattle=data;
        }
        else {
            currBattle=currfield.getFieldData();
        };

        int result=0;

        //current position
        result+=(currBattle[bombRow][bombCol]-'0');
        currBattle[bombRow][bombCol]='0';

        //horizontal elements
        for (int i=1;i<=power;i++) {
            if (bombRow-i>=0) {
                result+=(currBattle[bombRow-i][bombCol]-'0');
                currBattle[bombRow-i][bombCol]='0';
            };
            if (bombRow+i<=currBattle.size()-1) {
                result+=(currBattle[bombRow+i][bombCol]-'0');
                currBattle[bombRow+i][bombCol]='0';
            };
        };

        //for vertical elements
        for (int i=1;i<=power;i++) {
            if (bombCol-i>=0) {
                result+=(currBattle[bombRow][bombCol-i]-'0');
                currBattle[bombRow][bombCol-i]='0';
            };
            if (bombCol+i<=currBattle[bombRow].size()-1) {
                result+=(currBattle[bombRow][bombCol+i]-'0');
                currBattle[bombRow][bombCol+i]='0';
            };
        };

        currfield.populateField(currBattle);
        return 1;
    }



};



#endif