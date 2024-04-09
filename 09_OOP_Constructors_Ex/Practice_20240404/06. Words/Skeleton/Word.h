#ifndef WORDD_H
#define WORDD_H

#include <map>
#include <string>


class Word {

std::string wordInp;

static std::map<std::string,int> wordsM;

public:

    Word(const std::string & inp);

    const std::string & getWord() const;

    int getCount() const;

    bool operator<(const Word & other) const;
    
};



#endif