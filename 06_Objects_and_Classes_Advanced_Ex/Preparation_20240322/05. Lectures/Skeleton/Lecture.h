#ifndef LECTURE_H
#define LECTURE_H

#include "Resource.h"
#include "ResourceType.h"

#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>

using namespace std;

namespace SoftUni {

class Lecture {

    set<Resource> resV;
    map<ResourceType,int> resourceTypes;
    public:

    Lecture operator << (const Resource & second) {
        set<Resource>::iterator itFound=resV.find(second);
        if (itFound!=resV.end()){
                    resourceTypes[second.getType()]--;
                    resV.erase(itFound);
        };
        resV.insert(second);     
        resourceTypes[second.getType()]++;
        return *this;
    };

    set<Resource>::iterator begin() {
        return resV.begin();
    };

    set<Resource>::iterator end() {
        return resV.end();
    };

    int operator[] (ResourceType rt) {
        if (resourceTypes.find(rt)!=resourceTypes.end()) {
            return resourceTypes[rt];
        }
        else {
            return 0;
        };


    };


    friend vector<ResourceType> & operator<<(vector<ResourceType> & first, Lecture & second);


};

    vector<ResourceType> & operator<<(vector<ResourceType> & first, Lecture & second) {

        for (auto rtype : second.resourceTypes) {
            first.push_back(rtype.first);
        }
        return first;
    }




};



#endif