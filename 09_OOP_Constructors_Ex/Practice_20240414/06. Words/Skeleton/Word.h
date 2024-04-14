#ifndef woord_h
#define woord_h

#include <map>
#include <string>

class Word {

    static std::map<std::string,int> wordsM;
    std::string input;

    public:

        Word(const std::string & input);


        std::string getWord() const;

        size_t getCount() const;

        bool operator<(const Word & other) const;

};




#endif