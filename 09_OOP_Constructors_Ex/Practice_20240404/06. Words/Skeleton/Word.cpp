#include "Word.h"
#include <string>
#include <map>


// class Word {

std::map<std::string,int> Word::wordsM;

    Word::Word(const std::string & inp):wordInp(inp) {wordsM[wordInp]++;};

    const std::string & Word::getWord() const {
        return wordInp;
    };

    int Word::getCount() const {
        int count=wordsM[wordInp];
        wordsM.erase(wordInp);
        return count;
    };


    /*int Word::getCount() const {

        size_t count=wordsCount[wordCl];
        wordsCount.erase(wordCl);
        
        return count;
        };*/

    bool Word::operator<(const Word & other) const {
        return this->wordInp<other.wordInp;
    };
