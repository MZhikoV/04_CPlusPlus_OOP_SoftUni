#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

using namespace std;

namespace SoftUni {
    class Resource {
        int id;
        ResourceType rt;
        string url;

        public:

        bool operator < (const Resource & other) const {
            return this->id < other.id;
        }

        ResourceType getType () const {
            return rt;
        }

        friend istream & operator >> (istream & first, Resource & second);

        friend ostream & operator<< (ostream & first, const Resource & second);





    };

        istream & operator >> (istream & first, ResourceType & second) {
                    string buff;
                    first>>buff;
                    if (buff=="Presentation") {
                        second=ResourceType::PRESENTATION;
                    }
                    else if (buff=="Demo") {
                        second=ResourceType::DEMO;
                    }
                    else {
                        second=ResourceType::VIDEO;
                    }
                    return first;
                }

        //friend
        istream & operator >> (istream & first, Resource & second) {
            first>>second.id>>second.rt>>second.url;
            return first;
        };

        //friend 
        ostream & operator<< (ostream & first, const Resource & second) {
            first<<second.id<<' '<<second.rt<<' '<<second.url;
            return first;
        };
};

// Place your code here

#endif // !RESOURCE_H 
