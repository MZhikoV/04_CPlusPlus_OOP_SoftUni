#ifndef RESOURCE_H
#define RESOURCE_H

#include "ResourceType.h"

using SoftUni::ResourceType;

#include <string>
#include <sstream>
#include <map>
#include <set>
using namespace std;


namespace SoftUni {


class Resource {
    int id;
    ResourceType type;
    string link;

    public:

        Resource(): id(0) {};

        ResourceType getType() const {
            return this->type;
        };

         


        friend istream & operator>>(istream & istr, Resource & second);
        friend ostream & operator<<(ostream & ostr,const Resource & second );

        bool operator<(const Resource & other) const {
            return this->id<other.id;
        };


};

istream & operator>> (istream & istr, ResourceType & second) {
    string buffer;
    istr>>buffer;

    if (buffer=="Demo") {
        second=ResourceType::DEMO;
    }
    else if (buffer=="Presentation") {
        second=ResourceType::PRESENTATION;
    }
    else {
        second=ResourceType::VIDEO;
    };
    return istr;
}

istream & operator>>(istream & istr, Resource & second) {
   istr>>second.id>>second.type>>second.link;
    return istr;
};


ostream & operator<<(ostream & ostr,const Resource & second ) {
   ostr<<second.id<<' '<<second.type<<' '<<second.link;
    return ostr;
};
 



}

#endif // !RESOURCE_H 
