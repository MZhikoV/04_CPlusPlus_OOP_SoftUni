#include "Word.h"

std::map<std::string,size_t> Word::wordsCount; 

int Word::getCount() const {

        size_t count=wordsCount[wordCl];
        wordsCount.erase(wordCl);
        
        return count;
        };