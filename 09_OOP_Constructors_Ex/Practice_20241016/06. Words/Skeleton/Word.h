#ifndef woord_h
#define woord_h

#include <string>

class Word {
    std::string word;
    int count=0;
public:
    Word() {}
    Word(std::string inp) : word(inp) {this->count++;};

    std::string getWord() const {
        return this->word;
    };

    int getCount() const {
        return this->count;
    };

    bool operator<(const Word & other) {
        return this->word<other.word;
    };

    friend bool operator<(const Word& a, const Word& b );
};

    bool operator<(const Word& a, const Word& b) {
        return a.word<b.word;
    };


#endif