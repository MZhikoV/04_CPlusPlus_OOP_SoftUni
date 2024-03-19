#ifndef WORD_H
#define WORD_H

#include <string>
#include <sstream>
#include <map>

class Word {
    std::string wordCl;
    
    static std::map<std::string, size_t> wordsCount;
    

public:

    Word(const std::string & inpWord): wordCl(inpWord) {
        wordsCount[wordCl]++;
    };


    const std::string & getWord() const {return wordCl;}

    int getCount() const;

    bool operator< (const Word & other) const {
        return this->wordCl<other.wordCl;
    }


};


std::ostream& operator<<(std::ostream& out, const Word& w);

/*std::ostream& operator<<(std::ostream& out, const Word& w) {
	return out << w.getWord() << " " << w.getCount();
}

void printWordCounts(const std::string &line) {
	std::istringstream lineIn(line);
	std::set<Word> words;
	std::string wordStr;
	while (lineIn >> wordStr) {
		words.insert(Word(wordStr));
	}

	for (Word w : words) {
		std::cout << w << std::endl;
	}
}

int main() {
	std::string line;

	std::getline(std::cin, line);
	printWordCounts(line);

	std::cout << "---" << std::endl;

	std::getline(std::cin, line);
	printWordCounts(line);*/

#endif