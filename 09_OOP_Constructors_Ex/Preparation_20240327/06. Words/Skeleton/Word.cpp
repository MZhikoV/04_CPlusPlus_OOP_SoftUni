#include "Word.h"

#include <string>
#include <map>

std::map<std::string,size_t>Word::wordsCount;

    const std::string & Word::getWord() const {
        return word;
    };

    size_t Word::getCount() const {
        size_t count=wordsCount[word];
        wordsCount.erase(word);
        return count;
    };
