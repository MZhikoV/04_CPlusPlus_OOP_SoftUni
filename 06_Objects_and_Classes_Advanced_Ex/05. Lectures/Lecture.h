#ifndef LECTURE_H
#define LECTURE_H

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

#include "Resource.h"

using namespace std;

namespace SoftUni
{
    class Lecture
    {

        typedef set<Resource> setResource;

        map<ResourceType, int> resourceTypes;

        setResource resources;

    public:
        Lecture &operator<<(const Resource &r)
        {
            setResource::iterator itFound = resources.find(r);
            if (itFound != resources.end())
            {
                resourceTypes[r.getType()]--;
                resources.erase(itFound);
            }
            resources.insert(r);
            resourceTypes[r.getType()]++;
            return *this;
        }

        setResource::iterator begin() { return resources.begin(); };
        setResource::iterator end() { return resources.end(); };

        int operator[](ResourceType rt)
        {
            if (resourceTypes.find(rt) != resourceTypes.end())
            {
                return resourceTypes[rt];
            }
            else
            {
                return 0;
            }
        };

        friend vector<ResourceType> &operator<<(vector<ResourceType> &first,  Lecture &second);
    };

    vector<ResourceType> &operator<<(vector<ResourceType> &first, Lecture &second)
    {
        for (auto rType : second.resourceTypes)
        {
            first.push_back(rType.first);
        }

        return first;
    }

};

#endif // !LECTURE_H
