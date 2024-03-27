#ifndef WORD_H
#define WORD_H

#include <string>
#include <map>


class Word {

    std::string word;

    static std::map<std::string,size_t>wordsCount;

    public:
    Word(const std::string & word):word(word) {
        wordsCount[word]++;
    };

    const std::string & getWord() const;

    size_t getCount() const;

    bool operator<(const Word & other) const {
        return this->word<other.word;
    };
};



#endif