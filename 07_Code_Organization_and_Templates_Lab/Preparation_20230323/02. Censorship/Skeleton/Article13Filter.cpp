#include "Article13Filter.h"

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


	//Article13Filter filter(copyrighted);
// bool operator<(const Article13Filter & a, const Article13Filter & b) {
// 	return a<b;
// }


Article13Filter::Article13Filter(std::set<std::string> copyrighted): copyrighted(copyrighted) {};


bool Article13Filter::blockIfCopyrighted(std::string s) {
	return (isCopyrighted(s));
};

bool Article13Filter::isCopyrighted(std::string s) {
std::set<std::string>::iterator it=copyrighted.find(s);
if( it!=copyrighted.end()){
	blocked.push_back(s);
	return true;
	};
	return false;
	};

std::vector<std::string> Article13Filter::getBlocked() {
	return blocked;
}



