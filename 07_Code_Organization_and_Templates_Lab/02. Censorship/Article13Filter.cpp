#include "Article13Filter.h"

//using namespace std;

// class Article13Filter {
// private:
// 	std::set<std::string> copyrighted;
// 	std::vector<std::string> blocked;
// public:
// 	Article13Filter(std::set<std::string> copyrighted);
// 	bool blockIfCopyrighted(std::string s);
// 	bool isCopyrighted(std::string s);

// 	std::vector<std::string> getBlocked();
// };

Article13Filter::Article13Filter(std::set<std::string> copyrighted):copyrighted(copyrighted)  {};



bool Article13Filter::blockIfCopyrighted(std::string s) {
	if (isCopyrighted(s)) {
		blocked.push_back(s);
		return true;
	}
	else return false;

};

bool Article13Filter::isCopyrighted(std::string s) {
	return copyrighted.find(s)!=copyrighted.end();
};

std::vector<std::string> Article13Filter::getBlocked() {return blocked;};




