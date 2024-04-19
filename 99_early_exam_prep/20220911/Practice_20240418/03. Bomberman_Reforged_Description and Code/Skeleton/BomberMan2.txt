#ifndef BomberMan_h
#define BomberMan_h

#include <vector>

class BomberMan {

  void callme() {
    for(int i=0; i<10;i++) {
        for (int j=0;j<10;j++)
            std::cout<<comp[i][j];
        };
        std::cout<<std::endl;
    };

int bombPower =0;
//std::vector<std::vector<char>> comp{'0'};
char comp[10][10] {};

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

int placeBomb(std::vector<std::string> & gettedFeildData, int bombRow, int bombCol) {
    int result=0;

    std::vector<std::string> battlefield=gettedFeildData;

            //callme(battlefield);

        if ((bombRow)>=0) {
        std::string current=battlefield[bombRow];
        if (comp[bombRow][bombCol]!='X') {
        result+=current[bombCol]-'0';
        comp[bombRow][bombCol]=='X';
        };
        
        };

    //rows
    for (int i=1;i<=bombPower;i++) {
        if ((bombRow-i)>=0) {
        std::string current=battlefield[bombRow-i];
        if (comp[bombRow-i][bombCol]!='X') {
        result+=current[bombCol]-'0';
        comp[bombRow-i][bombCol]=='X';
        };
        };

        if ((bombRow+i)<battlefield.size()) {
        std::string current=battlefield[bombRow+i];
        if (comp[bombRow+i][bombCol]!='X') {
        result+=current[bombCol]-'0';
        comp[bombRow+i][bombCol]=='X';
        };
        };

        if ((bombCol-i)>=0) {
        std::string current=battlefield[bombRow];
        if (comp[bombRow][bombCol-i]!='X') {
        result+=current[bombCol-i]-'0';
        comp[bombRow][bombCol-i]=='X';
        };
        };

        if ((bombCol+i)<battlefield[bombRow].size()) {
        std::string current=battlefield[bombRow];
        if (comp[bombRow][bombCol+i]!='X') {
        result+=current[bombCol+i]-'0';
        comp[bombRow][bombCol-i]=='X';
        };
        };

        
    };
    callme();

    return result;
};



};


#endif