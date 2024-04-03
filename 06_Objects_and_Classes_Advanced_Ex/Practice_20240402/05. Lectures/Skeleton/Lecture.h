#ifndef LECTURE_H
#define LECTURE_H

#include "ResourceType.h"
#include "Resource.h"

#include <set>
#include <vector>
#include <map>
#include <string>

namespace SoftUni{

using namespace std;

class Lecture {
    typedef set<Resource> contR;

    contR resources;

    map<ResourceType, int> numberOfResourcesByType;

    public:
        Lecture () = default;

    Lecture & operator << (Resource & r) {
        contR::iterator itFound=resources.find(r);
        if (itFound!=resources.end()) {
            resources.erase(itFound);
            numberOfResourcesByType[r.getType()]--;
        };

        resources.insert(r);
        numberOfResourcesByType[r.getType()]++;
        return *this;
    };

    contR::iterator begin() {
        return resources.begin();
    };

    contR::iterator end() {
        return resources.end();
    };

   
    friend vector<ResourceType>& operator << (vector<ResourceType> & result, Lecture & rightSide);


    int operator[]( ResourceType & rType) {
        if (numberOfResourcesByType.find(rType)!=numberOfResourcesByType.end()) {
            return numberOfResourcesByType[rType];
        }
        else {
            return 0;
        }
    };

    // std::cout << "... by type:" << std::endl;
	// for (auto pair : numberOfResourcesByType) {
	// 	std::cout << pair.first << ": " << pair.second << std::endl;
	// }




};
    //friend
    vector<ResourceType>& operator << (vector<ResourceType> & result, Lecture & rightSide) {

            for (auto it2=rightSide.numberOfResourcesByType.begin(); it2!=rightSide.numberOfResourcesByType.end(); it2++) {
                result.push_back((*it2).first);
            };
        return result;
    };

};

#endif