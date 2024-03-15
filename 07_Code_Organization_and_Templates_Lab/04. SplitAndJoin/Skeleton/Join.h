#ifndef JOIN_H
#define JOIN_H

#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*std::string joined = "";
	if (type == 'i') {
		std::vector<int> numbers = split<int>(line, separator);
		joined = join(numbers, joinStr);
	}
	else if (type == 'w') {
		std::vector<std::string> words = split<std::string>(line, separator);
		joined = join(words, joinStr);
	}
	else if (type == 's') {
		std::vector<Song> songs = split<Song>(line, separator);
		joined = join(songs, joinStr);
	}
	else {
		std::cout << "[invalid input]" << std::endl;
	}*/

    template <typename T> string join(const vector<T> & inpVector, const string & joinString) {
        ostringstream buffer;

        bool bFirst=true;

        for (const T & vectorElem:inpVector){
            if(!bFirst) {
                buffer<<joinString;
            }
            else {
                bFirst=false;
            } 

            buffer<<vectorElem;
        }
        return buffer.str();
    }


#endif