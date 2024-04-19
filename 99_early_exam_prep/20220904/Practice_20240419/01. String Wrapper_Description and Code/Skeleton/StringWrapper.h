#ifndef StringWrapper_h
#define StringWrapper_H

#include <iostream>


class StringWrapper {

std::string word;
char letter;
int repetitions;

public:

    StringWrapper(std::string word) : word(word) {};
   // StringWrapper(std::string word) : word(word) {word+=word;};
    StringWrapper(char letter, int repetitions) : letter(letter), repetitions(repetitions) {
        while (repetitions--) {
            word+=letter;
        }
    };
    StringWrapper() : word(""), letter(0), repetitions(0) {};
    StringWrapper(const StringWrapper & other)=default;

    std::string getContent() const {
        return word;
    };

    StringWrapper& append(std::string a) {
       word+=a;
         return *this;
    };

    void printContent() const {
        std::cout<<word<<std::endl;
    };
};



#endif