#include "Word.h"



// class Word {

        std::map<std::string,int> Word::wordsM;
//     std::string input;

//     public:

        Word::Word(const std::string & input) : input(input) {wordsM[input]++;};


        std::string Word::getWord() const {
            return input;
        };

        size_t Word::getCount() const {
            size_t result=wordsM[input];
            wordsM.erase(input);
            return result;
        };

        bool Word::operator<(const Word & other) const {
            return this->input<other.input;
        };