#ifndef SPLIT_H
#define SpLIT_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

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






    template <typename T> vector<T> split(const string & line, const char & separator) {
            
            vector<T> result;

            istringstream istr(line);
            string buffer;

            while (getline(istr,buffer,separator)) {
                istringstream bufferStream(buffer);
                T temp;
                bufferStream>>temp;
                result.push_back(temp);
            };
            return result;
    };


#endif