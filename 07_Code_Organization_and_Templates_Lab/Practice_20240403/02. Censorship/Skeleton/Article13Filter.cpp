#include "Article13Filter.h"

using namespace std;

	// std::set<std::string> copyrighted;
	// std::vector<std::string> blocked;


	Article13Filter::Article13Filter(std::set<std::string> copyrighted) : copyrighted(copyrighted) {};



	bool Article13Filter::blockIfCopyrighted(std::string s) {
		if (isCopyrighted(s)) {
			blocked.push_back(s);
			return true;
		}
		else {
			return false;
		};
	};


	bool Article13Filter::isCopyrighted(std::string s) {
		auto itFound=copyrighted.find(s);

		if (itFound==copyrighted.end()) {
			return false;
		}
		else {
			return true;
		};
	};

	std::vector<std::string> Article13Filter::getBlocked(){
		return blocked;
	};

